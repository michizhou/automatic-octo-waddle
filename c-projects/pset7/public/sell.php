<?php

    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["stock"] === "")
        {
            apologize("Please enter a stock symbol.");
        }
        
        $stock = lookup($_POST["stock"]);
        
        if ($stock === false)
        {
            apologize("Invalid stock symbol entered!");
        }
        else
        {
            $rows = query("SELECT shares FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["code"]));
            if (count($rows) == 1)
            {
                $shares = $rows[0]["shares"];
            }
            else
            {
                apologize("Shares for requested symbol were not found.");
            }
            
            $value = $shares * $stock["price"];
            $name = strtoupper($_POST["stock"]);
            
            $request = query("DELETE FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["code"]));
            if ($request === false)
            {
                apologize("Errors occurred during selling.");
            }
            
            $request = query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
            if ($request === false)
            {
                apologize("Errors occurred during selling.");
            }
            $_SESSION["cash"] += $value;
            $type = 'SELL';
            
            $request = query("INSERT INTO history(id, action, date, symbol, shares, price) VALUES(?, ?, Now(), ?, ?, ?)", 
                $_SESSION["id"], 'SELL', strtoupper($_POST["code"]), $shares, $stock["price"]);
                
            render("receipt.php", ["title" => "Sell", "value" => $value, "type" => 'SELL', "name" => $name]);
        }
    }
    else
    {
        $rows = query("SELECT symbol FROM stocks WHERE id = ?", $_SESSION["id"]);
        render("sell_form.php", ["title" => "Sell", "symbols" => $rows]);
    }
?>
