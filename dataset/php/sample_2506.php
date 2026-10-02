<?php

function generate_sequence($n) {
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $i * ($i + 1) // 2;
    }
    return $sequence;
}

function optimize_transport($routes, $capacity) {
    $optimized_routes = array();
    foreach ($routes as $route) {
        if (array_sum($route) <= $capacity) {
            $optimized_routes[] = $route;
        }
    }
    return $optimized_routes;
}

function main() {
    $n = 5;
    $capacity = 15;
    $routes = generate_sequence($n);
    $optimized = optimize_transport(array($routes), $capacity);
    print_r($optimized);
}

main();
?>