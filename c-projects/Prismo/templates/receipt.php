<?php

    if ($type === 'DEPOSIT')
    {
        print("You have just deposited $amount dollars into your account.");
    }
    else if ($type === 'SELL')
    {
        print("You have sold all your shares of $name stock, for a total of $value dollars.");
    }
    else if ($type === 'BUY')
    {
        print("You have bought $shares shares of $name stock, for a total of $value dollars.");
    }
    else
    {
        apologize("Errors during processing of transaction.");
    }

?>
