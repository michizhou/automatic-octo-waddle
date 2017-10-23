/******************************************************************************
 *  Name: Michael Zhou    
 *  NetID: myzhou
 *  Precept: P05
 *
 *  Partner Name: Conway A. Niles   
 *  Partner NetID: cniles
 *  Partner Precept: P06
 * 
 ******************************************************************************/

Which partner is submitting the program files?

Michael Zhou

Programming Assignment 7: Markov Model

Hours to complete assignment (optional): 12~

/**********************************************************************
 * Describe the type parameters of your symbol table (i.e., what is   *
 * the key type and what is the value type). How did you use the      *
 * symbol table to implement the random() method.                     *
 **********************************************************************/
The first of the two symbol tables maintains kgrams and their frequency
of appearance while the second relates kgrams to integer arrays of
length 128, with each representing an ASCII character to categorize the 
frequency of that specific character appearing after certain kgrams. The
key type for both symbol tables are String types, while the value type for
the first table is an Integer object and int[] arrays for the second.
We first called the integer array of character frequencies for the given
kgram in random() and then used StdRandom.discrete() to generate a random
character with probability proportional to its frequency of being found 
after the kgram in the given text.

/**********************************************************************
 * The main() method we provide in the checklist does not test your   *
 * random() method. Describe how you tested it.                       *
 **********************************************************************/
We decided to write a loop that calls random() repeatedly, and count how 
many times a particular character is returned. Based on the frequencies
of these characters, we should expect the character to be returned some
certain number of times given enough iterations of the function. If the 
estimate of how many times a given character should be returned by the
random() function is similar to the actual frequency of the character 
behind a kgram, then random() method is properly weighing probabilities.

/**********************************************************************
 * Paste two of your favorite, not too long, output fragments here.   *
 * In addition to the pseudo-random text, indicate the order of your  *
 * model and what text file you used.                                 *
 **********************************************************************/
    gagagaaggcg (order: 2; input17.txt)
    Article shall exis (order: 6; amendments.txt)

/**********************************************************************
 * Did you receive help from classmates, past COS 126 students, or    *
 * anyone else?  Please list their names.  ("A Sunday lab TA" or      *
 * "Office hours on Thursday" is ok if you don't know their name.)    *
 **********************************************************************/
Monday office hours of Bridger Hahn and Marc Leef; also received some 
help from David Fan '19 and Bill Zhang '19.    

/**********************************************************************
 * Describe any serious problems you encountered.                     *
 **********************************************************************/
We were not able to completely decipher the issues we had with Text
Generator at first, getting stuck on the line that generated the random
character that was to be appended to the kgram as part of the string
that was to be printed as output. In the end, however, we did solve the
problem by adjusting how we wanted the subsequent kgrams from which the
random characters were generated to be incremented with each iteration.

/**********************************************************************
 *  List any other comments here.                                     *
 **********************************************************************/

