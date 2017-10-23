/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Determines whether if a list of three numbers entered are 
 *                actually ordered in either ascending or descending order.
 *                If the numbers are ordered as is, the program will print 
 *                out "true." Otherwise, it will print out "false."
 *
 ******************************************************************************/

public class Ordered {
    public static void main(String[] args) {
        
        // Initial boolean variable that determines if numbers are ordered
        boolean isSorted;
        
        // Integer values of numbers being inputted as command arguments
        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);
        int z = Integer.parseInt(args[2]);
        
        // Computing boolean value based on whether numbers are ordered
        isSorted = x < y && x < z && y < z;
        isSorted = isSorted || (x > y && x > z && y > z);
        
        // Prints out value of true or false based on presence of orderedness
        System.out.println(isSorted);
    }
 }
    