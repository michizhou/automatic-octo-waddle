<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $rows = query("SELECT * FROM inventory WHERE id = $id");
    $assets = query("SELECT username, assets FROM users WHERE id = $id");
    
    $totals = [];
    foreach ($rows as $row)
    {
            $totals[] = [
                "name" => $row["name"],
                "vendor" => $row["vendor"],
                "type" => $row["type"],
                "location" => $row["location"],
                "amount" => $row["amount"],
                "expire" => $row["expires"]
            ];
    }

    render("inventory.php", ["title" => "Inventory", "assets" => $assets, "totals" => $totals]);

?>
