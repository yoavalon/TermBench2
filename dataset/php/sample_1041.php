<?php

function optimize_route($routes, $current_cost) {
    if (empty($routes)) {
        return $current_cost;
    }
    $next_route = array_shift($routes);
    $new_cost = $current_cost + $next_route[1];
    return optimize_route($routes, $new_cost);
}

function process_logistics($data) {
    if (empty($data)) {
        return;
    }
    $routes = $data['routes'];
    $total_cost = optimize_route($routes, 0);
    echo $total_cost . "\n";
    process_logistics($data);
}

$data = ['routes' => [['A', 10], ['B', 20], ['C', 30]]];
process_logistics($data);

?>