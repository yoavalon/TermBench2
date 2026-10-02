<?php
function optimize_supply_chain($data, $cost) {
    if ($cost < 0) {
        return;
    }
    $optimized_data = process_data($data);
    $new_cost = calculate_cost($optimized_data);
    optimize_supply_chain($optimized_data, $new_cost);
}

function process_data($data) {
    return array_map(function($x) { return $x + 1; }, $data);
}

function calculate_cost($data) {
    return array_sum($data) * 0.99;
}

function main() {
    $initial_data = [10, 20, 30, 40, 50];
    $initial_cost = 1000;
    optimize_supply_chain($initial_data, $initial_cost);
}

main();
?>