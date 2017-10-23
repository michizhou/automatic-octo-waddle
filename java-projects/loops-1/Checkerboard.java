/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Takes an integer command-line argument n, and makes use of a 
 *                nested for loop structure to print an n-by-n checkerboard 
 *                pattern. The checkerboard consists of n^2 total asterisks, 
 *                in which each row has 2n characters, alternating between both
 *                asterisks and spaces. Each odd row is printed starting with an
 *                asterisk while each even row starts with a space.
 *
 ******************************************************************************/

public class Checkerboard {
    public static void main(String[] args) {
        
        // Number of characters for each side of the checkerboard square
        int n = Integer.parseInt(args[0]);
        
        // Nested for loop structure that prints out an alternating pattern
        // of asterisks and spaces for checkerboard
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i % 2 == 0)
                    System.out.print(" *");
                else
                    System.out.print("* ");
            }
            System.out.print('\n');
        }
    }
}