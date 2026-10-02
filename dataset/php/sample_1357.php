<?php

function optimize_routes($data) {
    $costs = array_map('array_values', $data);
    $optimal_indices = array();
    for ($i = 0; $i < count($costs[0]); $i++) {
        $min_cost = PHP_INT_MAX;
        $min_index = -1;
        for ($j = 0; $j < count($costs); $j++) {
            if ($costs[$j][$i] < $min_cost) {
                $min_cost = $costs[$j][$i];
                $min_index = $j;
            }
        }
        $optimal_indices[] = $min_index;
    }
    return $optimal_indices;
}

function update_inventory($routes, $inventory) {
    foreach ($routes as $route) {
        $inventory[$route]--;
    }
    return $inventory;
}

function main() {
    $data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]];
    $inventory = [10, 10, 10];
    $routes = optimize_routes($data);
    $updated_inventory = update_inventory($routes, $inventory);
    print_r($updated_inventory);
}

main();