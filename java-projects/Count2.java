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
public class Count2
{
    public static void main(String[] args)
    {
        int M = Integer.parseInt(args[0]);
        boolean[] b = new boolean[M];
        
        int count = 0;
        int distinct = 0;

        while (!StdIn.isEmpty()) {
            int value = StdIn.readInt();
            if (b[value] == false)
                b[value] = true;
            count++;
        }
        
        for (int i = 0; i < M; i++) {
            if (b[i])
                distinct++;
        }
        StdOut.printf("%d distinct values among %d integers\n", distinct, count);
    }
}