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
public class PlotMean {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        double total = 0.0;
        double mean = 0.0;
        double[] a = new double[n];
        
        StdDraw.setXscale(0, n-1);
        StdDraw.setPenRadius(.5/n);
        
        for (int i = 0; i < n; i++) {
            a[i] = Math.random();
        }
        for (int i = 0; i < n; i++) {
            total += a[i];
            mean = total / (i+1);
            StdDraw.setPenColor(StdDraw.BLACK);            
            StdDraw.point(i, a[i]);
            StdDraw.setPenColor(StdDraw.RED);
            StdDraw.point(i, mean);

        }
    }
}