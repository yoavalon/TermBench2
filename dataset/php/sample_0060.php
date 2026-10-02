<?php
function optimize_supply_chain($data) {
    $total_cost = 0;
    foreach ($data as $item) {
        $cost = $item['price'] * $item['quantity'];
        $total_cost += $cost;
    }
    return $total_cost;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [{'price': 10, 'quantity': 5}, {'price': 20, 'quantity': 10}, {'price': 15, 'quantity': 3}];
    $result = optimize_supply_chain($data);
    echo $result;
}
?>