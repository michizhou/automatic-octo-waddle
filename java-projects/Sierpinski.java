/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Draws a Sierpinski equilateral triangle pattern of order n
 *                using recursive calls to a function designed to draw patterns
 *                of filled equilateral triangles. An equilateral triangle is 
 *                first drawn as an outline for the overall pattern before the 
 *                the first recursion is called. This recursion draws a filled 
 *                triangle with half the big triangle's length, with its bottom 
 *                vertex at the midpoint of the outline's bottom side. Each call 
 *                of the function after draws three filled equilateral triangles 
 *                in the empty corners around each triangle of the previous order
 *                that are each half their size.
 * 
 ******************************************************************************/
public class Sierpinski {
    //  Calculates height of an equilateral triangle with a certain length
    public static double height(double length) {
        
        // computes height of an equilateral triangle based on their length
        double height = (length / 2) * Math.sqrt(3.0);
        return height;
    }

    //  Draws a filled equilateral triangle of the specified side length such
    //  that its bottom vertex is at the point (x, y)
    public static void filledTriangle(double x, double y, double length) {
        
        // establishes x- and y-coordinates of the vertices for the triangle
        double[] hori = { x, x - length / 2, x + length / 2 };
        double[] vert = { y, y + height(length), y + height(length)};
        
        // draws the equilateral triangle with vertices at the coordinates 
        // specified in the two arrays called
        StdDraw.filledPolygon(hori, vert);
    }
    //  Draws a Sierpinski triangle of order n, such that the largest filled
    //  triangle has its bottom vertex at (x, y) and sides of the specified length
    public static void sierpinski(int n, double x, double y, double length) {
        if (n == 0) return;
        filledTriangle(x, y, length);  // draws base triangle when order is zero
        
        // compute new lengths and heights of the three half-sized triangles
        double halfLength = length / 2;
        double triHeight = height(length);
        
        // recursively draw three half-sized equilateral triangles of order n-1
        sierpinski(n-1, x + halfLength, y, halfLength);  // lower-right triangle
        sierpinski(n-1, x - halfLength, y, halfLength);  // lower-left triangle
        sierpinski(n-1, x, y + triHeight, halfLength);   // upper triangle
    }
    //  Takes an integer command-line argument n;
    //  Draws the outline of an equilateral triangle of length 1 pointed upwards,
    //  with a bottom-left vertex at (0, 0) and bottom-right vertex is (1, 0); also
    //  draws a Sierpinski triangle of order n that fits snugly inside the outline.
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        
        double[] posX = { 0, 0.5, 1 }; // x-coordinates of outline vertices
        double[] posY = { 0, height(1.0), 0 }; // y-coordinates of vertices
        StdDraw.polygon(posX, posY); // draws the equilateral triangle outline
        
        double x = 0.5, y = 0.0; // bottom vertex of largest Sierpinski triangle
        sierpinski(n, x, y, 0.5);
    }
}