/*******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  
 ******************************************************************************/
public class Part1 {
    public static void main(String[] args) {
        // reads in the dimensions of the square board pattern
        int limit = Integer.parseInt(args[0]);
        
        // sets x- and y-scales of drawing window 
        StdDraw.setXscale(0, limit);
        StdDraw.setYscale(0, limit);
        
        // draws a N-by-N array of filled white and black squares
        for (int i = 1; i <= limit; i++) {
            for (int j = 1; j <= limit; j++) {
                // sets color of a specific square depending on the coordinates
                // of its upper-right corner and whether they divide evenly
                if (j % i == 0 || i % j == 0) 
                    StdDraw.setPenColor(StdDraw.BLACK); // black square if yes
               else 
                    StdDraw.setPenColor(StdDraw.WHITE); // white square if no
               // draws filled square with designated color from above
               StdDraw.filledSquare(i - 0.5, j - 0.5, 0.5);
            }
        }
    }
}