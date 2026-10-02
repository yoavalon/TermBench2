<?php

function update_inventory($stock, $orders) {
    for ($i = 0; $i < count($stock); $i++) {
        $stock[$i] += $orders[$i];
    }
    return $stock;
}

function generate_orders($num_items, $max_order) {
    $orders = [];
    for ($i = 0; $i < $num_items; $i++) {
        $orders[] = rand(0, $max_order);
    }
    return $orders;
}

function main() {
    $stock = [100, 150, 200, 250, 300];
    $num_items = count($stock);
    $max_order = 50;
    while (true) {
        $orders = generate_orders($num_items, $max_order);
        $stock = update_inventory($stock, $orders);
        print_r($stock);
    }
}

main();