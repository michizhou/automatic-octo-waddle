/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Produces a recursive drawing of a hybrid pattern with hexagonal
 *                frames surrounding central spaces with nested circles. Taking 
 *                one integer command-line argument n that controls the depth of
 *                the recursion, the program draws a repeating pattern of six
 *                hexagons within each larger hexagon of the previous iteration
 *                when the order n is between 1 and 7. The program first draws
 *                a large initial hexagon with a vertex pointing downward, upon
 *                which subsequent orders of hexagons base their orientation. 
 *                Each time the recursive function is called, each new hexagon 
 *                drawn is also filled in with a random color based on random
 *                number generation for RGB color values. The second part deals 
 *                with drawing in nested circle patterns in the center hexagonal
 *                space of each iteration for the main hexagonal pattern. The 
 *                nested circle pattern consists of nine circles, five of which
 *                are circles with half the radius of those of the four larger
 *                circles, all of which fit snugly in one giant circle for each
 *                order called in the iteration process.
 * 
 ******************************************************************************/
public class Grades {
    public static void main(String[] args) {
        
        // read in threshold below which no scores will be printed
        double n = Double.parseDouble(args[0]);
        
        // number of total assessments
        int NUM_OF_TESTS = 6; 
        
        // arrays for storing weights and maxscore
        double[] weight = new double[NUM_OF_TESTS];
        int[] maxScore = new int[NUM_OF_TESTS];
        
        // weight[i] is the weight value for assessment i
        StdIn.readString();
        for (int i = 0; i < NUM_OF_TESTS; i++) {
            weight[i] = StdIn.readDouble();
        }
        
         // maxScore[i] is the maximum score for assessment i
        StdIn.readString();
        for (int i = 0; i < NUM_OF_TESTS; i++) {
            maxScore[i] = StdIn.readInt();
        }
        
        while (!StdIn.isEmpty()) {
            
            // read in name of student, set read-in score and 
            // cumulative scores to zero
            String name = StdIn.readString();
            int score = 0;
            double total = 0.0;
            
            // read in score for each assessment and add to total for student
            for (int i = 0; i < NUM_OF_TESTS; i++) {
                score = StdIn.readInt();
                total = total + (weight[i] * score / maxScore[i]);
            }
            
            // print out only scores above the threshold and their students
            if (total >= n) {
                StdOut.printf("%.3f %s\n", total, name);
            }
            
        }
    }
}