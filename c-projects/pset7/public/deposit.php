<?php

    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["amount"]))
        {
            apologize("Please enter how much money you wish to deposit.");
        }
        else if ($_POST["amount"] <= 0 || is_numeric($_POST["amount"]) === false)
        {
            apologize("You must enter a valid amount of cash.");
        }
        else
        {
            $amount = $_POST["amount"];
            $id = $_SESSION["id"];
            $type = 'DEPOSIT';
   
            query("UPDATE users SET cash = cash + $amount WHERE id = $id");
            query("INSERT INTO history(id, action, amount, date) VALUES($id, 'DEPOSIT', $amount, Now())");

            render("receipt.php", ["title" => "Deposit", "amount" => $amount, "type" => 'DEPOSIT']);
        }
    }
    else
    {
        render("deposit_form.php", ["title" => "Deposit"]);
    }
?>
