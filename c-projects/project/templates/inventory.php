<table class="table table-striped">
    <thead>
        <tr>
            <th>Name</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price Bought</th>
            <th>Price Current</th>
            <th>Bought Value</th>
            <th>Current Value</th>
            <th>Gains / Losses</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($totals as $total): ?>
            <tr>
                <td><?= $total["name"]; ?></td>
                <td><?= $total["symbol"]; ?></td>
                <td><?= $total["shares"]; ?></td>
                <td><?= number_format($total["price_b"], 2); ?></td>
                <td><?= number_format($total["price_c"], 2); ?></td>
                <td><?= number_format($total["bvalue"], 2); ?></td>
                <td><?= number_format($total["cvalue"], 2); ?></td>
                <td><?= number_format($total["profit"], 2); ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>
<div>
    <a href="logout.php">Log Out</a>
</div>


