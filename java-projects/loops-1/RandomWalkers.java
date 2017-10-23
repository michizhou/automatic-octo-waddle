/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Takes two integer command-line arguments n and trials as input
 *                and then simulates the motion of a random walk for n steps as 
 *                entered. This will be repeated over a number of independent
 *                experiments equal to the value of trials. For each of these 
 *                random walks of n steps, the squared distance is computed.
 *                The program prints the final mean square distance, which is 
 *                the average of the trials squared distances.
 *
 ******************************************************************************/

public class RandomWalkers {
    public static void main(String[] args) {
        
        int steps = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        
        double totalDistance = 0.0;
        int count = 0;
        while (count < trials)
        {
            int x = 0, y = 0;
            for (int j = 0; j < steps; j++)
            {
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
            totalDistance += x*x + y*y;
            count++;
        }
        System.out.println("Mean Squared Distance = " + totalDistance/trials);
    }
}