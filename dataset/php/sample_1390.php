<?php

function load_data() {
    $data = [];
    for ($i = 1; $i <= 100; $i++) {
        $data[] = [
            'id' => $i,
            'quantity' => rand(1, 99),
            'cost' => rand(0, 999999) / 1000
        ];
    }
    return $data;
}

function optimize_supply_chain($data) {
    foreach ($data as &$row) {
        $row['optimized_quantity'] = $row['quantity'] * 1.1;
        $row['total_cost'] = $row['optimized_quantity'] * $row['cost'];
    }
    return $data;
}

function process_data() {
    $df = load_data();
    $optimized_df = optimize_supply_chain($df);
    return $optimized_df;
}

function main() {
    $result = process_data();
    print_r(array_slice($result, 0, 5));
}

main();