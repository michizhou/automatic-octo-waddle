/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Takes an integer command-line argument n as input and then
 *                simulates the motion of a random walk for n steps as entered.
 *                Each new location's coordinates are printed (including those
 *                at the starting point), in which the starting point is the 
 *                origin (0.0). Finally, the program prints the square of the
 *                final distance of the last position from the origin.
 *
 ******************************************************************************/

public class RandomWalker {
    public static void main(String[] args) {
        
        // Number of steps designated by input
        int steps = Integer.parseInt(args[0]);
        
        // Initial coordinates at point of origin
        int x = 0, y = 0;
        
        // Calculates and prints the new coordinates for each step taken based 
        // on the Math.random() function and computes square of distance for 
        // final coordinates from point of origin
        for (int i = 0; i < steps; i++)
        {
            System.out.println("(" + x + ", " + y + ')');
            double r = Math.random();
            if (r < 0.25)
                x++;
            else if (r < 0.50)
                y++;
            else if (r < 0.75)
                x--;
            else if (r < 1.00)
                y--;
        }
        System.out.println("(" + x + ", " + y + ')');
        int dist = x*x + y*y;
        System.out.println("Squared Distance = " + dist);
    }
}