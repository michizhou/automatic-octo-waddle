/******************************************************************************
  *  Name:    Michael Zhou
  *  NetID:   myzhou
  *  Precept: P05
  *
  *  Partner Name:    Conway Niles
  *  Partner NetID:   cniles
  *  Partner Precept: P06
  * 
  *  Description: Represents a Markov model of order k from a given text string.
  *               Takes given text and generates two symbol tables of character
  *               sequences, or kgrams, derived from the text with length k. 
  *               The first symbol table stores distinct kgrams and the number 
  *               of times they appear in the text, while the second table is 
  *               responsible for storing the kgrams and the frequencies of the 
  *               characters which follow them in the text. It can also return
  *               a string representation of the Markov model and can return a 
  *               random character that follows a specified kgram in the text
  *               with its probability weighted on the number of times the
  *               character follows the kgram in the text.
  *
  ******************************************************************************/

public class MarkovModel {
    
    private static final int ASCII = 128; // list of ascii integers
    
    private int order;  // order of Markov model
    private ST<String, Integer> kGrams; // Symbol Table relating kgrams to their
                                        // frequency
    private ST<String, int[]> charData; // Symbol Table relating kgrams to
                                        // integer arrays denoting frequency
                                        // of characters after a given kgram
    
    // creates a Markov model of order k for the specified text
    public MarkovModel(String text, int k) {
        // defining the order of markov model as k
        order = k;
        
        // creating circular String
        String textAppend = text + text.substring(0, order);
        
        // defining the symbol table for the kGram/frequency values
        kGrams = new ST<String, Integer>();
        
        
        // Filling the symbol table kGrams, with key kGram and
        // value frequency as well as creating the kgram substrings
        for (int i = 0; i < text.length(); i++) {
            // String kgram key of length k that is found within text
            String kgram = textAppend.substring(i, i+order);
            int kGramFreq = 1; // frequency of kgram appearing in text
            
            if (kGrams.contains(kgram)) {
                int temp = kGrams.get(kgram); // frequency of kgram appearances
                kGrams.put(kgram, temp + 1);
            }
            else {
                kGrams.put(kgram, kGramFreq);
            }
        }
        
        // declaring a second symbol table with a String key for kgrams and an
        // integer array that stores the frequencies of all ASCII characters
        // that appear right after a certain kgram
        charData = new ST<String, int[]>();
        
        for (int i = 0; i < text.length(); i++) {
            // array for frequencies of characters appearing after kgrams
            int[] asciiChars = new int[ASCII];
            // String kgram key of length k that is found within text
            String kgram = textAppend.substring(i, i + order);
            char ch = textAppend.charAt(i+order); // character after a kgram
            
            if (!charData.contains(kgram)) {
                charData.put(kgram, asciiChars);
            }
            // frequency of kgram appearances in text
            int[] temp = charData.get(kgram); 
            temp[ch]++;
            
        }
    }
    
    // returns the order k of this Markov model
    public int order() {
        return order;
    }
    
    // returns a string representation of the Markov model (as described below)
    public String toString() {
        
        String kString = ""; // total string representation of Markov model
        for (String key : charData.keys()) {
            String seq = key + ':';  // string representation for a given kgram
            for (int i = 0; i < ASCII; i++) {
                // frequency of a character appearing after a kgram
                int freq = freq(key, (char) i); 
                if (freq != 0) {
                    seq = seq + " " + (char) (i) + " " + freq;   
                }
            }
            kString = kString + seq + '\n';   
        }
        return kString;
    }
    
    // returns the number of times the specified kgram appears in the text
    public int freq(String kgram) {
        // return runtime error of IllegalArgumentException if length of kgram
        // does not match value of order k
        if (kgram.length() != order) {
           throw new IllegalArgumentException();
        }
        if (kGrams.contains(kgram)) {
            int value = (int) (kGrams.get(kgram));
            return value;
        } 
        else {
            return 0;   
        }
    }
    
    // returns the number of times the character c follows the specified
    // kgram in the text
    public int freq(String kgram, char c) {
        // return runtime error of IllegalArgumentException if length of kgram
        // does not match value of order k
        if (kgram.length() != order) {
           throw new IllegalArgumentException();
        }
        // array of frequencies for characters appearing after given kgram
        int[] tempArray = charData.get(kgram); 
        if (charData.contains(kgram)) {
            int times = tempArray[c];   // times a character appears after kgram
            return times;
        }
        else {
            return 0;
        }
        
    }
    
    // returns a random character that follows the specified kgram in the text,
    // chosen with weight proportional to the number of times that character
    // follows the specified kgram in the text
    public char random(String kgram) {
         // return runtime error if length of kgram does not match order k
         if (kgram.length() != order) {
           throw new IllegalArgumentException();
         }  
         // return runtime error if charData system table does not have kgram
         if (!charData.contains(kgram)) {
          throw new IllegalArgumentException();   
         }
        // array of frequencies for characters appearing after kgram
        int[] tempArray = charData.get(kgram);
        // weighted probability of a random character in array appearing 
        // after the given kgram
        int prob = StdRandom.discrete(tempArray); 
        char randomc = (char) prob;   // random character generated after kgram 
        return randomc;
    }
    
    // unit tests all methods in this class
    // taken from course website-
    public static void main(String[] args) {
        
        // general tests for testing freq() methods (2 and 1-arg) with given
        // text being read in from the program
        String text1 = "banana";
        MarkovModel model1 = new MarkovModel(text1, 2);
        StdOut.println("freq(\"an\", 'a')    = " + model1.freq("an", 'a'));
        StdOut.println("freq(\"na\", 'b')    = " + model1.freq("na", 'b'));
        StdOut.println("freq(\"na\", 'a')    = " + model1.freq("na", 'a'));
        StdOut.println("freq(\"na\")         = " + model1.freq("na"));
        StdOut.println();
        
        String text3 = "one fish two fish red fish blue fish"; 
        MarkovModel model3 = new MarkovModel(text3, 4);
        StdOut.println("freq(\"ish \", 'r') = " + model3.freq("ish ", 'r'));
        StdOut.println("freq(\"ish \", 'x') = " + model3.freq("ish ", 'x'));
        StdOut.println("freq(\"ish \")      = " + model3.freq("ish "));
        StdOut.println("freq(\"tuna\")      = " + model3.freq("tuna"));
        
        // test for function of random() 
        for (int i = 0; i < 20; i++) {
            int count1 = 0;
            int count3 = 0;
            char temp1 = model1.random("na");
            char temp3 = model3.random("fish");
            if (temp1 == 'b') {
                count1++;
            }
            if (temp3 == 'o') {
                count3++;
            }
            System.out.println(count1 + " " + count3);         
        }
    }
}
