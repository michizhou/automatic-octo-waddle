<div id="account_container">
    <div class="left_side">
        <strong>Username :</strong>
    </div>
    <div class="right_side">
        <?php print($info[0]["username"]); ?>
    </div><br/>
    <div class="left_side">
        <strong>Password :</strong>
    </div>
    <div class="right_side">
        <?php print("<a href='password.php'>Change Password</a>"); ?>
    </div><br/>
    <div class="left_side">
        <strong>Cash :</strong>
    </div>
    <div class="right_side">
        <?php print($info[0]["cash"]); ?>
    </div>
</div>
