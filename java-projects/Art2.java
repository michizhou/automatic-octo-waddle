/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Produces a recursive drawing of a hexagonal pattern. Taking 
 *                one integer command-line argument n that controls the depth of
 *                the recursion, the program draws a repeating pattern of seven
 *                hexagons within each larger hexagon of the previous iteration
 *                when the order n is between 1 and 7. The program first draws
 *                a large initial hexagon with a vertex pointing downward, upon
 *                which subsequent orders of hexagons base their orientation. 
 *                Each time the recursive function is called, each new hexagon 
 *                drawn is also filled in with a random color based on random
 *                number generation for RGB color values. 
 * 
 ******************************************************************************/
public class Art2 {
    // plots an "H" centered on (x, y), using 3 lines, each of length size
    private static void drawHex(double x, double y, double hexLength) {
        
        // compute the coordinates of the six vertices of the hexagon
        double[] vertx = { x, x - Math.sqrt(3.0)*hexLength / 2, 
            x - Math.sqrt(3.0)*hexLength / 2, x, x + Math.sqrt(3.0)*hexLength / 2,
            x + Math.sqrt(3.0)*hexLength / 2 }; 
        double[] verty = { y, y + hexLength / 2, y + 3*hexLength / 2, y + 2*hexLength,
            y + 3*hexLength / 2, y + hexLength / 2 };
        
        // draw the six edges of the hexagon
        StdDraw.filledPolygon(vertx, verty);    // shape of the hexagon
    }
    
    // plot an H-tree of order n, centered at (x, y) of the given side length
    private static void hexFractal(int n, double x, double y, double length) {
        
        StdDraw.setPenColor(StdRandom.uniform(255), StdRandom.uniform(255),
                                StdRandom.uniform(255));
        
        if (n == 0) return;
        drawHex(x, y, length);
        
        // compute x- and y-coordinates of the 4 half-size H-trees
        double nHexLength = length/3;
        double halfD = Math.sqrt(3.0)*nHexLength / 2;
        
        // recursively draw 4 half-size H-trees of order n-1
        hexFractal(n-1, x-halfD, y + nHexLength / 2, nHexLength);  // lower left  H-tree
        hexFractal(n-1, x-2*halfD, y + 2*nHexLength, nHexLength);    // lower left  H-tree
        hexFractal(n-1, x-halfD, y + 7*nHexLength/2, nHexLength);    // lower left  H-tree
        hexFractal(n-1, x, y + 2*nHexLength, nHexLength);    // lower left  H-tree
        hexFractal(n-1, x+halfD, y + 7*nHexLength/2, nHexLength);    // lower left  H-tree
        hexFractal(n-1, x+2*halfD, y + 2*nHexLength, nHexLength);    // lower left  H-tree
        hexFractal(n-1, x+halfD, y + nHexLength / 2, nHexLength);
    }
    
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        
        double x = 0.0, y = -7.5;   // bottom vertex of hexagon fractal
        double hexLength = 7.5;         // side length of H-tree
        
        StdDraw.setScale(-8.0, 8.0);
        hexFractal(n, x, y, hexLength);
    }
}