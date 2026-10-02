<?php
function calculate_cost($route, $costs) {
    $sum = 0;
    for ($i = 0; $i < count($route) - 1; $i++) {
        $sum += isset($costs[$route[$i] . ',' . $route[$i + 1]]) ? $costs[$route[$i] . ',' . $route[$i + 1]] : 0;
    }
    return $sum;
}

function find_optimal_route($routes, $costs) {
    $min_cost = INF;
    $best_route = null;
    foreach ($routes as $route) {
        $cost = calculate_cost($route, $costs);
        if ($cost < $min_cost) {
            $min_cost = $cost;
            $best_route = $route;
        }
    }
    return $best_route;
}

function main() {
    $routes = [['A', 'B', 'C'], ['A', 'C', 'B'], ['B', 'A', 'C']];
    $costs = ['A,B' => 10, 'B,C' => 15, 'C,A' => 20];
    $optimal_route = find_optimal_route($routes, $costs);
    print_r($optimal_route);
}

main();
?>