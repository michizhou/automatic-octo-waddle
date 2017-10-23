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
public class GStatistic {
    public static void main(String[] args) {
        
        int n = StdIn.readInt();
        int nonzero = 0;
        double gStat = 0.0;
        
        while (!StdIn.isEmpty()) {
            
            double obsX = StdIn.readDouble();
            int expY = StdIn.readInt();
            if (expY != 0.0) {
                nonzero++;
            }
            if (obsX != 0.0) {
                gStat += 2 * obsX * Math.log(obsX / expY);
            }
        }
        int degFreedom = nonzero - 1;
        StdOut.println("degrees of freedom = " + degFreedom);
        StdOut.printf("G-statistic        = %.4f\n", gStat);
    }
}