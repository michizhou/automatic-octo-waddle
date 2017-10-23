/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Draws and animates a simulation of the n-body problem with 
 *                various scenarios for gravitationally bound systems acting as
 *                sources of input. Each input file begins with an integer that
 *                designates the number of objects n in the system, a value for
 *                the radius of the simulated universe, and statistics for each
 *                object. In particular, they are the positions, velocities, 
 *                mass, and image filename. The program takes in two command-line 
 *                arguments that it stores as values for running time and time 
 *                increment for the animation, as well as the input file's object
 *                data, which is stored in parallel arrays
 * 
 ******************************************************************************/
public class NBody {
    public static void main(String[] args) {
        // Reads in command-line arguments for values of running time and time
        // increment, sets time counter to zero, and sets gravitational constant
        double maxT = Double.parseDouble(args[0]);
        double deltaT = Double.parseDouble(args[1]);
        double realTime = 0.0;
        double GRAV_CONSTANT = 6.67e-11;
        
        // Reads in values for number of objects and the radius of the universe
        int partNum = StdIn.readInt();
        double rad = StdIn.readDouble();
        
        // Initializes arrays for positions, velocities, mass, and image filename
        double[] posx = new double[partNum];
        double[] posy = new double[partNum];
        double[] vx = new double[partNum];
        double[] vy = new double[partNum];
        double[] mass = new double[partNum];
        String[] pfile = new String[partNum];
        
        // Initializes arrays for net forces and accelerations of objects
        double[] forceX = new double[partNum]; 
        double[] forceY = new double[partNum];
        double[] accelX = new double[partNum];
        double[] accelY = new double[partNum];
        
        // Reads in values for each object's initial position coordinates,
        // velocities, mass, and image filename and puts into respective arrays
        for (int i = 0; i < partNum; i++) {
            posx[i] = StdIn.readDouble();
            posy[i] = StdIn.readDouble();
            vx[i] = StdIn.readDouble();
            vy[i] = StdIn.readDouble();
            mass[i] = StdIn.readDouble();
            pfile[i] = StdIn.readString();
        }
        
        while (realTime < maxT) {
            // Set the scale of the drawing window
            StdDraw.setScale(-rad, rad);
            StdDraw.enableDoubleBuffering(); 
            
            // Set the background to display a predetermined image
            StdDraw.picture(0.0, 0.0, "starfield.jpg");
            
            // Display all n bodies on the screen at their present positions
            for (int i = 0; i < partNum; i++) {
                // Draw celestial object on the screen
                StdDraw.picture(posx[i], posy[i], pfile[i]);
            }
            
            // Show and pause object for 20 ms
            StdDraw.show();
            StdDraw.pause(20);
            
            // Calculates the net forces acting on an object from other bodies
            for (int i = 0; i < partNum; i++) { 
                // Sets initial forces from x and y directions to zero
                forceX[i] = 0.0; 
                forceY[i] = 0.0;
                for (int j = 0; j < partNum; j++) {
                    // Calculates part of net force by another object on first,
                    // except for the case where the objects are the same
                    if (i == j) {
                        forceX[i] += 0; 
                        forceY[i] += 0; }
                    else {
                        double distC = Math.pow((posx[i]-posx[j])*(posx[i]-posx[j])
                                       + (posy[i]-posy[j])*(posy[i]-posy[j]), 1.5);
                        forceX[i] = forceX[i] + (GRAV_CONSTANT*mass[i]*mass[j]*
                                                 (posx[j]-posx[i])) / distC;
                        forceY[i] = forceY[i] + (GRAV_CONSTANT*mass[i]*mass[j]*
                                                 (posy[j]-posy[i])) / distC;  
                    }
                }
            }
            
            for (int i = 0; i < partNum; i++) {
                // Calculates acceleration in x and y directions from net forces
                accelX[i] = forceX[i] / mass[i];
                accelY[i] = forceY[i] / mass[i];
                
                // Updates velocities of each object with each time increment
                vx[i] = vx[i] + deltaT*accelX[i];
                vy[i] = vy[i] + deltaT*accelY[i];
                
                // Updates position coordinates of each object with each time step
                posx[i] = posx[i] + deltaT*vx[i];
                posy[i] = posy[i] + deltaT*vy[i];
            }
            
            // Updates time counter of simulation
            realTime = realTime + deltaT;
        } 
        
        // Prints out number of objects and the radius of the drawn universe
        StdOut.printf("%d\n", partNum);
        StdOut.printf("%.2e\n", rad);
        for (int i = 0; i < partNum; i++) {
            // Prints out final position coordinates, velocities, mass, and
            // image filename for each celestial object
            StdOut.printf("%11.4e %11.4e %11.4e %11.4e %11.4e %12s\n",
                          posx[i], posy[i], vx[i], vy[i], mass[i], pfile[i]);
        }
    }
} 