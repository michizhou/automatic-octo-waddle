/*******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  
 ******************************************************************************/
public class Aliquot
{
    public static void main(String[] args) {
       
        int num = Integer.parseInt(args[0]);
        int aliSum = 0;
        
        for (int i = 1; i <= num/2; i++) {
            if (num % i == 0) {
                aliSum += i;
            }
        }
        
        StdOut.println("The Aliquot sum of " + num + " is " + aliSum);
    }
}