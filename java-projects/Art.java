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
public class Art {
    // plots a hexagon with a bottom vertex at (x,y) and specified side length
    private static void drawHex(double x, double y, double hexLength) {
        
        // compute the coordinates of the six vertices of the hexagon
        double[] vertx = { x, x - Math.sqrt(3.0)*hexLength, 
            x - Math.sqrt(3.0)*hexLength, x, x + Math.sqrt(3.0)*hexLength,
            x + Math.sqrt(3.0)*hexLength }; 
        double[] verty = { y, y + hexLength, y + 3*hexLength, y + 4*hexLength,
            y + 3*hexLength, y + hexLength };
        
        // draw the six edges of the hexagon
        StdDraw.filledPolygon(vertx, verty);    // shape of the hexagon
    }
    
    // plot a hexagonal fractal pattern of order n, with each smaller hexagon 
    // having a new side length that is a third of its larger hexagon and the
    // bottom vertex of the lowest hexagon at (x,y)
    private static void hexFrac(int n, double x, double y, double length) {
        
        // sets at random the RGB values for the color of the filled hexagons
        StdDraw.setPenColor(StdRandom.uniform(255), StdRandom.uniform(255),
                                StdRandom.uniform(255));
        if (n == 0) return;
        drawHex(x, y, length/2); // draws base hexagon when order is zero
        
        // compute x- and y-coordinates of the 4 half-size H-trees
        double nHexLength = length/3;
        double halfD = Math.sqrt(3.0)*nHexLength / 2;
        
        // recursively draw 6 third-sized hexagons of order n-1
        hexFrac(n-1, x-halfD, y + nHexLength / 2, nHexLength); // lower left hexagon
        hexFrac(n-1, x-2*halfD, y + 2*nHexLength, nHexLength); // midleft hexagon
        hexFrac(n-1, x-halfD, y + 7*nHexLength/2, nHexLength); // upper left hexagon
        hexFrac(n-1, x+halfD, y + 7*nHexLength/2, nHexLength); // upper right hexagon
        hexFrac(n-1, x+2*halfD, y + 2*nHexLength, nHexLength); // midright hexagon
        hexFrac(n-1, x+halfD, y + nHexLength / 2, nHexLength); // lower right hexagon
        
        // draw initial nested circles pattern in center space
        pearlDraw(n-1, x, y + 3*nHexLength, halfD);    // center nested circles
 
    }
    
    // Plots patterns of nine nested circles in the center hexagonal space of 
    // each iteration of hexagonal patterns as well as within each circle of
    // the nested circles pattern of the previous order n.
    private static void pearlDraw(int n, double w, double z, double rad) {
        
        // sets at random the RGB values for the color of the circle outlines
        StdDraw.setPenColor(StdRandom.uniform(0, 255), 
                            StdRandom.uniform(0, 255), StdRandom.uniform(0, 255));
        
        if (n == 0) return;
        StdDraw.circle(w, z, rad); // draws base circle when order is zero
        
        pearlDraw(n-1, w, z, rad/5); // center small circle
        pearlDraw(n-1, w + 3*rad/5, z - 3*rad/5, rad/5); // down-right small circle
        pearlDraw(n-1, w - 3*rad/5, z + 3*rad/5, rad/5); // up-left small circle
        pearlDraw(n-1, w + 3*rad/5, z + 3*rad/5, rad/5); // up-right small circle
        pearlDraw(n-1, w - 3*rad/5, z - 3*rad/5, rad/5); // down-left small circle
        pearlDraw(n-1, w - 3*rad/5, z, 2*rad/5); // left large circle
        pearlDraw(n-1, w + 3*rad/5, z, 2*rad/5); // right large circle
        pearlDraw(n-1, w, z + 3*rad/5, 2*rad/5); // upper large circle
        pearlDraw(n-1, w, z - 3*rad/5, 2*rad/5); // lower large circle
    }
    // Takes an integer command-line argument as the order n;
    // Draws the initial filled hexagon of the fractal pattern, with bottom
    // vertex at (x0, y0) and predetermined side length; also draws a pattern
    // of smaller hexagons that fits snugly inside the main hexagon
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        
        double x0 = 0.0, y0 = -7.5;   // bottom vertex of initial hexagon
        double hexLength = 7.5;         // side length of main hexagon
        
        StdDraw.setScale(-8.0, 8.0);  // set scale of drawing window
        hexFrac(n, x0, y0, hexLength); 
    }
}