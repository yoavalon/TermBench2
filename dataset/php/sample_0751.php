<?php

function optimize_route($cost_matrix, $current_route, $visited, $total_cost) {
    if (count($current_route) == count($cost_matrix)) {
        return $total_cost;
    }
    $min_cost = PHP_INT_MAX;
    for ($i = 0; $i < count($cost_matrix); $i++) {
        if (!in_array($i, $visited)) {
            $visited[] = $i;
            $cost = optimize_route($cost_matrix, array_merge($current_route, [$i]), $visited, $total_cost + $cost_matrix[end($current_route)][$i]);
            array_pop($visited);
            if ($cost < $min_cost) {
                $min_cost = $cost;
            }
        }
    }
    return $min_cost;
}

function main() {
    $cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]];
    $initial_route = [0];
    $visited = [0];
    $result = optimize_route($cost_matrix, $initial_route, $visited, 0);
    echo $result;
}

main();