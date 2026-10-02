<?php
function optimize_route($routes, $visited, $current, $destination, $cost) {
    if ($current == $destination) {
        return $cost;
    }
    $min_cost = INF;
    foreach ($routes[$current] as $route) {
        if (!in_array($route[0], $visited)) {
            $visited[] = $route[0];
            $new_cost = optimize_route($routes, $visited, $route[0], $destination, $cost + $route[1]);
            $visited = array_diff($visited, [$route[0]]);
            if ($new_cost < $min_cost) {
                $min_cost = $new_cost;
            }
        }
    }
    return $min_cost;
}

function find_optimal_path($routes, $start, $end) {
    $visited = [$start];
    return optimize_route($routes, $visited, $start, $end, 0);
}

$routes = ['A' => [['B', 10], ['C', 15]], 'B' => [['C', 35], ['D', 25]], 'C' => [['D', 30]], 'D' => []];
$start = 'A';
$end = 'D';
echo find_optimal_path($routes, $start, $end);
?>