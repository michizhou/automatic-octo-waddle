<?php
    
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["code"]))
        {
            apologize("Please enter a stock symbol!");
        } 
        
        $stock = lookup($_POST["code"]);
        if ($stock === false)
        {
            apologize("Stock symbol is invalid.");
        }
        else
        {
            $name = $stock["name"];
            $symbol = $stock["symbol"];
            $price = number_format($stock["price"], 2);
            render("result.php", ["title" => "Quote", "name" => $name, "symbol" => $symbol, "price" => $price]);
        }
    } 
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }
?>
