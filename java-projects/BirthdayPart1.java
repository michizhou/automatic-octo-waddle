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
public class BirthdayPart1 {
    public static void main(String[] args) {
        int frequency = Integer.parseInt(args[0]);
        int[] bdays = new int[366];
        int totalCount = 0;
        int target = -2;
        
        while (!StdIn.isEmpty() && target == -2) {
            int date = StdIn.readInt();
            bdays[date]++;
            totalCount++;
            if (bdays[date] == frequency) 
                target = date;
        }
        
        if (target == -2)
            StdOut.println("No birthday occurs " + frequency + " times");
        else
            StdOut.println(totalCount + " birthdays examined to find " + frequency +
                           " occurrences of " + target);     
    }
}