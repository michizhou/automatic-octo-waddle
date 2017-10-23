/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Creates objects that model vibrating guitar strings, which
 *                depend on the ring buffer of the sounds produced by the 
 *                string. Simulates the plucking of guitar strings and advances
 *                the Karplus-String simulation for each pluck. Returns the 
 *                final samples of sound produced at the end of the plucks.
 *
 ******************************************************************************/

public class GuitarString {    

    private RingBuffer buffer; // initialized ring buffer of a guitar string
    
    // creates a guitar string of the specified frequency,
    // using sampling rate of 44,100
    public GuitarString(double frequency) {
        int n = (int) Math.ceil(44100/frequency);
        buffer = new RingBuffer(n);
        for (int i = 0; i < n; i++) {
            buffer.enqueue(0);
        }
    }

    // creates a guitar string whose size and initial values are given by
    // the specified array
    public GuitarString(double[] init) {
        int alength = init.length;
        buffer = new RingBuffer(alength);
        for (int i = 0; i < alength; i++) {
            buffer.enqueue(init[i]);
        }
    }

    // returns the number of samples in the ring buffer
    public int length() {
        int buflength = buffer.size();
        return buflength;
    }

    // plucks the guitar string (by replacing the buffer with white noise)
    public void pluck() {
        for (int i = 0; i < buffer.size(); i++) {
            buffer.dequeue();
            buffer.enqueue(StdRandom.uniform(-0.5, 0.5));
        }
    }

    // advances the Karplus-String simulation one time step
    public void tic() {
        double first = buffer.dequeue();
        double second = buffer.peek();
        double avgDecay = 0.996 * (first + second) / 2;
        buffer.enqueue(avgDecay);
    }

    // returns the current sample
    public double sample() {
        double current = buffer.peek();
        return current;
    }

    // unit tests this class
    public static void main(String[] args) {
        // initial test for public methods in GuitarString class
        double[] samples = { 0.2, 0.4, 0.5, 0.3, -0.2, 0.4, 0.3, 0.0, -0.1, -0.3 };  
        GuitarString testString = new GuitarString(samples);
        int m = 25; // 25 tics
        for (int i = 0; i < m; i++) {
            double sample = testString.sample();
            System.out.printf("%6d %8.4f\n", i, sample);
            testString.tic();        
        }
        // tests for length() and sample() using first GuitarString() function
        GuitarString strA = new GuitarString(10);
        GuitarString strB = new GuitarString(100);
        GuitarString strC = new GuitarString(1000);
        System.out.println(strA.length()+ " " + strB.length() + " " +strC.length());
        System.out.println(strA.sample()+ " " + strB.sample() + " " +strC.sample());
        
        // tests for length() and sample() using second GuitarString() function
        double[] seqA = {1, 2, 3, 4, 5};
        double[] seqB = {5, 10, 15, 20, 25};
        double[] seqC = {3, 6, 9, 12, 15};
        GuitarString str1 = new GuitarString(seqA);
        GuitarString str2 = new GuitarString(seqB);
        GuitarString str3 = new GuitarString(seqC);
        System.out.println(str1.length()+ " " + str2.length() + " " +str3.length());
        System.out.println(str1.sample()+ " " + str2.sample() + " " +str3.sample());
        
        double[] tests = {2, 1.6, 6.4, 25.6, 102.4};
        double[] tests1 = {3, 8.1, 24.3, 72.9, 218.7};
        
        // test for pluck() with length() and sample() used as checks
        GuitarString run = new GuitarString(tests);
        System.out.println(run.length() + " " + run.sample());
        run.pluck();
        System.out.println(run.length() + " " + run.sample());

        // test for tic() with length() and sample() used as checks
        GuitarString run1 = new GuitarString(tests1);
        System.out.println(run1.length() + " " + run1.sample());
        run1.tic();
        System.out.println(run1.length() + " " + run1.sample());    
    }

}
