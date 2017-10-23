<?php

    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["stock"]))
        {
            apologize("Please enter a stock symbol.");
        }
        if (empty($_POST["shares"]) || !is_numeric($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Please enter an appropriate number of shares!");
        }
        
        $stock = lookup($_POST["stock"]);
        if ($stock === false)
        {
            apologize("Invalid stock symbol entered!");
        }
        else
        {            
            $value = $_POST["shares"] * $stock["price"];
            $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            $name = strtoupper($_POST["stock"]);
            
            if ($cash[0]["cash"] < $value)
            {
                apologize("You do not have enough money for this transaction!");
            }
            else
            {
                $request = query("INSERT INTO stocks(id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE 
                shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]);
                if ($request === false)
                {
                    apologize("Errors occurred while buying.");
                }
            
                $request = query("UPDATE users SET cash = cash - ? WHERE id = ?", $value, $_SESSION["id"]);
                if ($request === false)
                {
                    apologize("Errors occurred while buying.");
                }
                $type = 'BUY';
                
                $request = query("INSERT INTO history(id, action, date, symbol, shares, price, amount) VALUES(?, ?, Now(), ?, ?, ?, ?)", 
                    $_SESSION["id"], 'BUY', strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"], $stock["price"] * $_POST["shares"]);
                
                render("receipt.php", ["title" => "Buy", "value" => $value, "type" => 'BUY', "name" => $name, "shares" => $shares]);
            }
        }
    }
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
?>
