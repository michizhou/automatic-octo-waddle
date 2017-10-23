<?php

    require("../includes/config.php");    
    
    $id = $_SESSION["id"];
    
    $info = query("SELECT username, cash FROM users WHERE id = $id");
    
    render("account_form.php", ["title" => "Account", "info" => $info]);
    
?>
