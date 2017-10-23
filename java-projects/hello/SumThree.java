/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  This program is designed to take in a string of integers as int
 *                type command-line arguments, printing the three integers and 
 *                their total sum in the format of an addition equation.
 *                
 *
 ******************************************************************************/
public class SumThree {
    public static void main(String[] args) {
        
        // Prints out the three input integers along with their sum in the form
        // of a proper mathematical equation with proper symbols included
        System.out.print(args[0] + " + " + args[1] + " + " + args[2] + " = ");
        System.out.println(Integer.parseInt(args[0]) + Integer.parseInt(args[1])
                          + Integer.parseInt(args[2]));
    }
}