<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["username"] === "" || $_POST["password"] === "" || $_POST["confirm"] === "") 
        {
            apologize("All fields must be filled");
        }
        else if ($_POST["password"] !== $_POST["confirm"])
        {
            apologize("Passwords don't match!");
        }
        else 
        {
            $result = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
            if ($result === false)
            {
                apologize("Username is already taken");
            }
            else
            {
                $rows = query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                $_SESSION["id"];
                redirect("index.php");
            }
        }
    }   
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
