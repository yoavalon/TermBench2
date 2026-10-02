<?php
function optimize_route($routes, $current_route, $visited, $cost) {
    if (count($current_route) == count($routes)) {
        return $cost;
    }
    $min_cost = PHP_FLOAT_MAX;
    for ($i = 0; $i < count($routes); $i++) {
        if (!in_array($i, $visited)) {
            $new_cost = $cost + $routes[$current_route[count($current_route) - 1]][$i];
            $new_visited = array_merge($visited, [$i]);
            $new_route = array_merge($current_route, [$i]);
            $min_cost = min($min_cost, optimize_route($routes, $new_route, $new_visited, $new_cost));
        }
    }
    return $min_cost;
}

function find_min_cost($routes) {
    $min_cost = PHP_FLOAT_MAX;
    for ($i = 0; $i < count($routes); $i++) {
        $min_cost = min($min_cost, optimize_route($routes, [$i], [$i], 0));
    }
    return $min_cost;
}

function main() {
    $routes = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]];
    echo find_min_cost($routes);
}
main();
?>