<?php $stocks = query("SELECT symbol FROM stocks WHERE id = ?", $_SESSION["id"]); ?>

<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class = "form-control input-lg" name="stock">
            <option value = ""></option>
            <?php foreach($stocks as $stock): ?>
                <option value = "<?= $stock["symbol"] ?>" ><?= $stock["symbol"] ?></option>
            <? endforeach ?>
            </select> 
        </div>
        <div class="form-group">
            <button type="submit" class="btn">Sell</button>
        </div>
    </fieldset>
</form>
