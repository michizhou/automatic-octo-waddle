/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Converts values from RGB format to CMYK format of color. Reads 
 *                three integer command-line arguments as the values for red,
 *                green, and blue respectively before printing the RGB values and
 *                the corresponding CMYK values derived from certain mathematical
 *                formulas. If the red, green, and blue values are all 0, the 
 *                program will display values of 0 or 0.0 for all colors except
 *                for black, which will be displayed with a value of 1.0.
 *
 ******************************************************************************/

public class RGBtoCMYK {
    public static void main(String[] args) {
         
        // Calculated values of red, green, and blue
        int red = Integer.parseInt(args[0]);
        int green = Integer.parseInt(args[1]);
        int blue = Integer.parseInt(args[2]); 
        
        // Values for white, cyan, magenta, yellow, and black respectively
        double white = Math.max(red/255.0, Math.max(blue/255.0, green/255.0));
        double cvalue = (white - red/255.0) / white;
        double mvalue = (white - green/255.0) / white;
        double yvalue = (white - blue/255.0) / white;
        double bvalue = 1 - white;
        
        // Conditional unique to situation of red, blue, and green all being 0
        if (red == 0 && green == 0 && blue == 0) 
        {
            cvalue = 0.0;
            mvalue = 0.0;
            yvalue = 0.0;
        }
        
        // Prints out RGB values and corresponding CMYK values on screen
        System.out.println("red     = " + args[0]);
        System.out.println("green   = " + args[1]);
        System.out.println("blue    = " + args[2]);
        System.out.println("cyan    = " + cvalue);
        System.out.println("magenta = " + mvalue);
        System.out.println("yellow  = " + yvalue);
        System.out.println("black   = " + bvalue);   
    }
    
}