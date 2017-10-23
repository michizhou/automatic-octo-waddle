/*******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Determines the number of electoral votes won by each candidate
 *                in an election and the number of votes needed to win. The names
 *                of the candidates are first read in at the start of the input
 *                file before moving on to reading in the data for each region's
 *                election results. Each region in the input file has its name,
 *                the total number of electoral votes at stake in that region,
 *                and the votes gained by each candidate in that region. In the 
 *                case of a tie, neither of the candidates wins electoral votes.
 *                The number of votes needed to win is then calculated, and the
 *                total numbers of electoral votes won by both candidates is
 *                printed along with their names and the number of votes needed
 *                to win the election as output.
 * 
 ******************************************************************************/
public class Election {
    // calculates smallest integer strictly greater than half of a given number
    public static int majorityOf(int n) {
        // number of votes needed to gain a lead and win the election
        int lead = 0;
        // calculates number needed to gain majority, depending on if the 
        // starting number is even or odd
        if (n % 2 != 0)
            lead = (n + 1) / 2;
        else
            lead = (n / 2) + 1;
        return lead;
    }
    public static void main(String[] args) {
        // reads in names of the candidates
        String cand1name = StdIn.readString();
        String cand2name = StdIn.readString();
        
        // number of electoral votes available for a region, total electoral
        // votes counted from all regions, and votes needed to win the election
        int elecVotes = 0;
        int totalElectoralVotes = 0;
        int victoryAmt = 0;
        
        // total number of electoral votes won by each candidate
        int cand1total = 0; 
        int cand2total = 0;
        
        while (!StdIn.isEmpty()) {
            // reads in the name of the region, total electoral votes available,
            // and the number of votes for each candidate
            StdIn.readString();
            elecVotes = StdIn.readInt();
            int cand1Votes = StdIn.readInt();
            int cand2Votes = StdIn.readInt();
            
            // awards all electoral votes to the candidate with most votes or 
            // none of them in the case of a tie
            if (cand1Votes == cand2Votes) {
                cand1total += 0;
                cand2total += 0;
            }
            else if (cand1Votes > cand2Votes) 
                cand1total += elecVotes;
            else 
                cand2total += elecVotes;
            
            // increments the total amount of electoral votes available
            totalElectoralVotes += elecVotes;
        }
        // calculates amount of electoral votes needed to win the election
        victoryAmt = majorityOf(totalElectoralVotes);
        
        // prints out the candidates' names, their electoral vote totals, and 
        // the number of votes needed to win a strict majority
        StdOut.println(cand1name + " " + cand1total);
        StdOut.println(cand2name + " " + cand2total);
        StdOut.println(victoryAmt + " needed to win");
    }
}