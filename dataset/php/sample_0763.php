<?php
function optimize_route($cost_matrix, $path, $visited, $total_cost) {
    if (count($path) == count($cost_matrix)) {
        return $total_cost + $cost_matrix[end($path)][$path[0]];
    }
    $min_cost = PHP_FLOAT_MAX;
    for ($i = 0; $i < count($cost_matrix); $i++) {
        if (!in_array($i, $visited)) {
            $new_cost = optimize_route($cost_matrix, array_merge($path, [$i]), array_merge($visited, [$i]), $total_cost + $cost_matrix[end($path)][$i]);
            if ($new_cost < $min_cost) {
                $min_cost = $new_cost;
            }
        }
    }
    return $min_cost;
}

function find_min_cost($cost_matrix) {
    $min_cost = PHP_FLOAT_MAX;
    for ($i = 0; $i < count($cost_matrix); $i++) {
        $cost = optimize_route($cost_matrix, [$i], [$i], 0);
        if ($cost < $min_cost) {
            $min_cost = $cost;
        }
    }
    return $min_cost;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]];
    echo find_min_cost($cost_matrix);
}
?>