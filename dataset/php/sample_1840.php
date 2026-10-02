<?php
function optimize_supply_chain($data) {
    $total_cost = 0.0;
    foreach ($data as $item) {
        $total_cost += $item['quantity'] * $item['price'];
    }
    return round($total_cost, 2);
}

function main() {
    $data = [['quantity' => 150.75, 'price' => 2.34], ['quantity' => 200.5, 'price' => 1.8], ['quantity' => 120.25, 'price' => 3.15]];
    $result = optimize_supply_chain($data);
    echo $result;
}

main();
?>