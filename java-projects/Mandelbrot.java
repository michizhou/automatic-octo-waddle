/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Produces a recursive drawing of a particular pattern. Taking 
 *                one integer command-line argument n that controls the depth of
 *                the recursion, the program stays within the drawing window when
 *                n is between 1 and 7. 
 * 
 ******************************************************************************/
public class Mandelbrot {
    public static void main(String[] args) {
        
        
        int width = 1920, height = 1080, max = 1000;
        int black = 0x000000, white = 0xFFFFFF;
    for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
        double c_re = (col - width/2.0)*4.0/width;
        double c_im = (row - height/2.0)*4.0/width;
        double x = 0, y = 0;
        int iteration = 0;
        while (x*x+y*y <= 4 && iteration < max) {
            double x_new = x*x - y*y + c_re;
            y = 2*x*y + c_im;
            x = x_new;
            iteration++;
        }
        if (iteration < max) putpixel(col, row, white);
        else putpixel(col, row, black);
    }
}
    }
}