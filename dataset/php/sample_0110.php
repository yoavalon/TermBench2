<?php

function optimize_supply_chain($data) {
    $processed_data = [];
    foreach ($data as $item) {
        if ($item['quantity'] > 0) {
            $processed_data[] = $item;
        }
    }
    return $processed_data;
}

function analyze_boundaries($data) {
    $min_quantity = INF;
    $max_quantity = -INF;
    foreach ($data as $item) {
        if ($item['quantity'] < $min_quantity) {
            $min_quantity = $item['quantity'];
        }
        if ($item['quantity'] > $max_quantity) {
            $max_quantity = $item['quantity'];
        }
    }
    return array($min_quantity, $max_quantity);
}

function main() {
    $supply_data = array(array('product' => 'A', 'quantity' => 10), array('product' => 'B', 'quantity' => 0), array('product' => 'C', 'quantity' => 25));
    $optimized_data = optimize_supply_chain($supply_data);
    list($min_q, $max_q) = analyze_boundaries($optimized_data);
    echo "Minimum Quantity: $min_q, Maximum Quantity: $max_q";
}

main();

?>