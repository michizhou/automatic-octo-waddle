<?php
    
    require_once("PHPMailer/class.phpmailer.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {    
        $mail = new PHPMailer();
    
        $mail->IsSMTP();
        $mail->Host = "smtp.comcast.net";
    
        $mail->SetFrom($_POST["email"]);
    
        $mail->AddAddress($_POST["email"]);
    
        $mail->Subject = "Password Change and Reset";
    
        $mail->Body = "You have requested to change your password. Follow the link to set up a new one: <html><a href="reset_form.php">Reset Password</html>" .
    }
    
    if ($mail->Send() === false)
    {
        die($mail->ErrorInfo . "\n");
        return 0;
    }
    else
    {
        render("forgot_form.php", ["title" => "Forgot Password"]);
    }
?>
