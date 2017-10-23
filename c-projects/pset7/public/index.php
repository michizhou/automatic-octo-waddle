<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $rows = query("SELECT * FROM stocks WHERE id = $id");
    $cash = query("SELECT username, cash FROM users WHERE id = $id");
    
    $totals = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $totals[] = [
                "name" => $stock["name"],
                "symbol" => $row["symbol"],
                "price_b" => $row["price"],
                "price_c" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "bvalue" => $row["price"] * $row["shares"],
                "cvalue" => $stock["price"] * $row["shares"],
                "profit" => $stock["price"] * $row["shares"] - $row["price"] * $row["shares"]
            ];
        }
    }

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "cash" => $cash, "totals" => $totals]);

?>
