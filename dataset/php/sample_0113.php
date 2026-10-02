<?php

function generate_supply_data($num_items) {
    $data = [];
    for ($i = 0; $i < $num_items; $i++) {
        $data[] = [
            'item_id' => rand(1, 1000),
            'quantity' => rand(10, 100),
            'cost' => mt_rand() / mt_getrandmax() * 15 + 5
        ];
    }
    return $data;
}

function optimize_supply_chain($data) {
    $total_cost = 0;
    foreach ($data as $item) {
        $total_cost += $item['quantity'] * $item['cost'];
    }
    $average_cost = $total_cost / count($data);
    $optimized_data = array_filter($data, function($item) use ($average_cost) {
        return $item['cost'] <= $average_cost;
    });
    return $optimized_data;
}

function main() {
    $num_items = 50;
    $supply_data = generate_supply_data($num_items);
    $optimized_data = optimize_supply_chain($supply_data);
    echo "Optimized supply chain data: " . print_r($optimized_data, true);
}

main();