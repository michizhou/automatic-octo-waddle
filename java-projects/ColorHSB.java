/*************************************************************************
 *  Name:         Michael Zhou
 *  Login:        myzhou
 *
 *  
 *  Simpler linear regression data type.
 *  Reads a sequence of observation pairs from standard input,
 *  computes the best-fit line, and prints out the observation
 *  pairs and the predicted values.
 *
 *
 *************************************************************************/

public class ColorHSB {
    
    private final double MDEG = 360.0; // maximum degrees in a full circle
    private int h; // hue of the newly created color 
    private int sat; // purity of the color's hue
    private int br; // percentage of white in the color 
    
    // constructor for ColorHSB object type
    public ColorHSB(int h,  int s, int b) {
        // sets the object's instance variables from input values
        this.h = h;
        this.sat = s;
        this.br = b;
    }
    // string representation of this color
    public String toString() {
        String color = ""; // initial state of color string
        color = color + "(" + h + ", " + sat + ", " + br + ")"; 
        return color; 
    }
    // does this color represent a shade of gray?
    public boolean isGrayScale() {
        // if saturation and brness of color are both 0 then color is gray
        if (sat == 0 && br == 0)
            return true;
        // if saturation or brness of color is 0 then color is grayish
        else if (sat == 0 || br == 0)
            return true;
        return false; // if neither value is 0, then color is not grayscale
    }
    // squared distance between two colors
    public int distanceSquaredTo(ColorHSB otherC) {
        // difference between hues of two colors
        int hdiff = (this.h - otherC.h);
        
        // minimum of square of difference between hues of two colors and the
        // square of difference between MDEG and absolute value of difference
        double min = Math.min(hdiff * hdiff, (MDEG - Math.abs(hdiff)) *
                             (MDEG - Math.abs(hdiff)));
        // squared distance between two colors
        int sqdist = (int) (min + (this.sat - otherC.br) * (this.sat - otherC.br)
            + (this.br - otherC.sat) * (this.br - otherC.sat));
        return sqdist;
    }
    // test client code for main methods of class
    public static void main (String[] args) {
        int h0 = Integer.parseInt(args[0]);  // value of hue for original color
        int s0 = Integer.parseInt(args[1]);  // value of saturation for original color
        int b0 = Integer.parseInt(args[2]);  // value of brightness for original color
        
        ColorHSB original = new ColorHSB(h0, s0, b0); // object for original color
        int mdist = Integer.MAX_VALUE;  // value for minimum distance 
        String found = ""; // name of color closest to original
        String nearC = ""; // representation of values for nearest color
        
        while (!StdIn.isEmpty()) {
            // name of color read in from standard input
            String colName = StdIn.readString();
            
            int h1 = StdIn.readInt();  // value of hue for defined color
            int s1 = StdIn.readInt();  // value of saturation for defined color
            int b1 = StdIn.readInt();  // value of brightness for defined color
            
            // object for a pre-defined color
            ColorHSB otherColor = new ColorHSB(h1, s1, b1); 
            // squared distance between original and pre-defined colors
            int colDist = original.distanceSquaredTo(otherColor);
            if (colDist < mdist)
            {
                mdist = colDist;
                found = colName;
                nearC = otherColor.toString();
            }          
        }
        StdOut.println(found + " " + nearC);
    }
}