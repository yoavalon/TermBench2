<?php

function evaluate_supply_chain($data, $threshold) {
    $total_cost = 0;
    foreach ($data as $item) {
        if ($item['demand'] > $threshold) {
            $total_cost += $item['cost'];
        }
    }
    return $total_cost;
}

function optimize_inventory($data, $max_budget) {
    foreach ($data as &$item) {
        if ($item['cost'] > $max_budget) {
            $item['quantity'] = 0;
        } else {
            $item['quantity'] = intdiv($max_budget, $item['cost']);
        }
    }
    return $data;
}

function main() {
    $supply_data = [
        ['product' => 'A', 'cost' => 10, 'demand' => 100, 'quantity' => 0],
        ['product' => 'B', 'cost' => 20, 'demand' => 200, 'quantity' => 0],
        ['product' => 'C', 'cost' => 15, 'demand' => 150, 'quantity' => 0]
    ];
    $budget = 500;
    $threshold = 150;
    $supply_data = optimize_inventory($supply_data, $budget);
    $total_cost = evaluate_supply_chain($supply_data, $threshold);
    echo $total_cost;
}

main();