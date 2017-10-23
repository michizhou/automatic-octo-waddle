<?php
    
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["password"])) 
        {
            apologize("Please enter a new password");
        }
        else if (empty($_POST["confirm"]))
        {
            apologize("Please confirm your new password");
        }
        else if ($_POST["password"] != $_POST["confirm"])
        {
            apologize("Passwords do not match!");
        }
        else
        {
            $hash = crypt($_POST["password"]);
            $id = $_SESSION["id"];
            query("UPDATE users SET hash = $hash WHERE id = $id");
            render(".php");
        }
    }
    else
    {
        render("reset_form.php", ["title" => "Password Reset"]);
    }
?>
