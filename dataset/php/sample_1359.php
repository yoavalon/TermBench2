<?php

function generate_shipments($data) {
    $mutated_data = [];
    foreach ($data as $item) {
        $new_item = $item;
        $new_item['quantity'] = (int)($new_item['quantity'] * mt_rand(80, 120) / 100);
        $new_item['lead_time'] = (int)($new_item['lead_time'] * mt_rand(90, 110) / 100);
        $mutated_data[] = $new_item;
    }
    return $mutated_data;
}

function optimize_inventory($data) {
    $optimized_data = [];
    foreach ($data as $item) {
        if ($item['quantity'] > 100) {
            $item['quantity'] = 100;
        }
        if ($item['lead_time'] < 5) {
            $item['lead_time'] = 5;
        }
        $optimized_data[] = $item;
    }
    return $optimized_data;
}

function main() {
    $initial_data = [['item' => 'A', 'quantity' => 120, 'lead_time' => 4], ['item' => 'B', 'quantity' => 90, 'lead_time' => 6], ['item' => 'C', 'quantity' => 150, 'lead_time' => 3]];
    $mutated_data = generate_shipments($initial_data);
    $optimized_data = optimize_inventory($mutated_data);
    print_r($optimized_data);
}

main();