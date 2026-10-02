<?php

function optimize_routes($routes, $current_route = null) {
    if ($current_route === null) {
        $current_route = [];
    }
    if (empty($routes)) {
        return [$current_route];
    }
    $optimized_routes = [];
    foreach ($routes[0] as $next_step) {
        $new_routes = optimize_routes(array_slice($routes, 1), array_merge($current_route, [$next_step]));
        $optimized_routes = array_merge($optimized_routes, $new_routes);
    }
    return $optimized_routes;
}

function analyze_supply_chain() {
    while (true) {
        $supply_chain = [['A1', 'A2'], ['B1', 'B2', 'B3'], ['C1', 'C2']];
        $optimized_routes = optimize_routes($supply_chain);
    }
}

analyze_supply_chain();