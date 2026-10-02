<?php
function optimize_routes($routes, $demands, $capacities) {
    for ($i = 0; $i < count($routes); $i++) {
        if ($demands[$i] > $capacities[$i]) {
            $routes = redistribute_load($routes, $demands, $capacities, $i);
        }
    }
    return $routes;
}

function redistribute_load($routes, $demands, $capacities, $index) {
    $excess = $demands[$index] - $capacities[$index];
    for ($j = 0; $j < count($routes); $j++) {
        if ($j != $index && $capacities[$j] > 0) {
            $transfer = min($excess, $capacities[$j]);
            $demands[$j] += $transfer;
            $demands[$index] -= $transfer;
            $excess -= $transfer;
            if ($excess == 0) {
                break;
            }
        }
    }
    return $routes;
}

function main() {
    $routes = [[1, 2], [3, 4], [5, 6]];
    $demands = [10, 15, 20];
    $capacities = [10, 10, 10];
    $optimized_routes = optimize_routes($routes, $demands, $capacities);
    print_r($optimized_routes);
}

main();
?>