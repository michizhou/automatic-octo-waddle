 /*****************************************************************************
 *  Name: Michael Zhou
 *  NetID: myzhou
 *  Precept: P05
*
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 *
 *  Description: Simulates the actions of a linear feedback shift register that
 *               performs discrete step operations that shifts the bits of a 
 *               bit register sequence one position to the left and replaces the
 *               vacated bit by the exclusive or (xor) of the bit being shifted
 *               off and the bit that was previously occupying a certain tap 
 *               position in the register. Program first takes in an LFSR bit
 *               sequence and initializes instance variables that record the 
 *               number of bits in the LFSR, creates a register array for storing
 *               the individual bits, and stores the specified tap position. It
 *               then can simulate one or multiple steps of the LFSR and print 
 *               the modified LFSR sequences after each step along with the newly
 *               substituted bit of the sequence or a k-bit integer. Program also
 *               has test code designed to evaluate the correctness in execution
 *               of the public methods under the LFSR class.
 * 
 *****************************************************************************/

public class LFSR {
        private int n;     // number of bits in the LFSR
        private int[] reg; // reg[i] = ith bit of LFSR, reg[0] is rightmost bit
        private int tapPosition; // tap position
    
    // constructor for the LFSR responsible for initializing instance variables
    // and reading in the seed to set up the register array
    public LFSR(String seed, int tap) {
        tapPosition = tap; // sets tap position based on bit position specified
        n = seed.length(); // assigns seed length as number of bits in LFSR
        reg = new int[n];  // sets size of array for register based on LFSR bits
        
        // assigns to a certain register bit (with rightmost bit in seed reg[0]) 
        // value of 0 or 1 based on corresponding character value in seed
        for (int i = 0; i < n; i++) {
            char c = seed.charAt(i);
            if (c == '0')
                reg[n-i-1] = 0;
            else
                reg[n-i-1] = 1;
        }
    }
    
    // returns a k-bit integer obtained by simulating k steps of the LFSR by
    // doubling a variable and adding the bit returned by step() for each step
    public int generate(int k) {
        int sumtotal = 0; // initial value variable representing the integer
        for (int i = 0; i < k; i++) {
            sumtotal = sumtotal * 2;
            sumtotal += step();
        }
        return sumtotal;
    }
    
    // returns the last register bit after simulating one step of the LFSR through 
    // using the exclusive-or function on the tap and last register bits
    public int step() {
        int temp = reg[n-1] ^ reg[tapPosition]; // value of exclusive-or function bit
        // shifts the register bits to the right in the register array
        for (int i = 1; i < n; i++) {
            reg[n-i] = reg[n-i-1];
        }
        reg[0] = temp; // assigns value exclusive-or function bit to first register
        return reg[0];
    }
    
    // returns the string version of the modified LFSR sequence based on the current 
    // values in the register bit array and their arrangement
    public String toString() {
        String strSequence = ""; // initial sequence for the LFSR string
        for (int i = 0; i < n; i++) {
            strSequence += reg[n-i-1];
        }
        return strSequence;
    }
    public static void main(String[] args) {
        
        // test code for the generate() method through an initial seed that 
        // prints out modified LFSR sequences after calls to generate() function
        LFSR lfsr = new LFSR("01101000010", 8);
        StdOut.println(lfsr);
        for (int i = 0; i < 10; i++) {
            int r = lfsr.generate(5);
            StdOut.println(lfsr + " " + r);
        }
        // test code for the step() method through an initial seed that prints
        // out modified LFSR sequences after calls to step() function
        LFSR lfsr1 = new LFSR("01101010011", 8);
        StdOut.println(lfsr1);
        for (int i = 0; i < 10; i++) {
            int bit = lfsr1.step();
            StdOut.println(lfsr + " " + bit);
        }
        // test code for the toString() method that prints out the initial seed
        // as its equivalent LFSR sequence after call to toString() function
        LFSR lfsr2 = new LFSR("01101001110", 8);
        StdOut.println(lfsr2);
    }
}