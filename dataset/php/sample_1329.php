<?php
function calculate_route_costs($routes) {
    $costs = [];
    foreach ($routes as $route) {
        $cost = array_sum($route);
        $costs[] = $cost;
    }
    return $costs;
}

function optimize_routes($routes, $budgets) {
    $optimized_routes = [];
    foreach ($routes as $index => $route) {
        if (array_sum($route) <= $budgets[$index]) {
            $optimized_routes[] = $route;
        }
    }
    return $optimized_routes;
}

function main() {
    $routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]];
    $budgets = [150, 200, 250];
    $costs = calculate_route_costs($routes);
    $optimized_routes = optimize_routes($routes, $budgets);
    print_r($optimized_routes);
}

main();
?>