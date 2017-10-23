<table class="table table-striped">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Total Amount</th>
        </tr>
    </thead>
    
    <?php
    
        foreach ($history as $history) 
        {
                print("<tr>");    
                print("<td>{$history["action"]}</td>");
                print("<td>{$history["date"]}</td>");
                print("<td>{$history["symbol"]}</td>");
                print("<td>{$history["shares"]}</td>");
                print("<td>" . number_format($history["price"], 2) . "</td>");   
                print("<td>" . number_format($history["amount"], 2) . "</td>"); 
                print("</tr>");             
        }
    ?>
</table>
<div>
    <a href="logout.php">Log Out</a>
</div>
