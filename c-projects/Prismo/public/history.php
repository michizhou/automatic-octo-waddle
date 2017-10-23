<?php

    require("../includes/config.php");
    
    $history = query("SELECT action, date, symbol, shares, price, amount FROM history WHERE id = ? ORDER BY date DESC", $_SESSION["id"]);
        
    if (count($history) === 0)
    {
        apologize("No transactions for this user exist.");   
    }
    
    render("record.php", ["title" => "History", "history" => $history]);

?>
