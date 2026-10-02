<?php

function optimize_supply_chain($data) {
    $cost = 0;
    foreach ($data as $item) {
        $cost += $item['demand'] * $item['price'];
    }
    return $cost;
}

function adjust_inventory($data, $budget) {
    foreach ($data as &$item) {
        if ($item['cost'] > $budget) {
            $item['demand'] = 0;
        } else {
            $item['demand'] = rand(1, 10);
        }
    }
    return $data;
}

function main() {
    $supply_data = [
        ['name' => 'A', 'demand' => 5, 'price' => 20, 'cost' => 50],
        ['name' => 'B', 'demand' => 3, 'price' => 30, 'cost' => 40],
        ['name' => 'C', 'demand' => 8, 'price' => 10, 'cost' => 30]
    ];
    $budget = 100;
    $adjusted_data = adjust_inventory($supply_data, $budget);
    $total_cost = optimize_supply_chain($adjusted_data);
    echo $total_cost;
}

main();