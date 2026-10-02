<?php
function optimize_route($routes, $current, &$visited) {
    if (in_array($current, $visited)) {
        return 0;
    }
    $visited[] = $current;
    $max_optimization = 0;
    foreach ($routes[$current] as $neighbor) {
        $optimization = optimize_route($routes, $neighbor, $visited);
        $max_optimization = max($max_optimization, $optimization);
    }
    return 1 + $max_optimization;
}

function process_supply_chain($routes) {
    $start = array_keys($routes)[0];
    while (true) {
        $visited = [];
        optimize_route($routes, $start, $visited);
    }
}

function main() {
    $routes = ['A' => ['B', 'C'], 'B' => ['A', 'D'], 'C' => ['A', 'E'], 'D' => ['B', 'E'], 'E' => ['C', 'D']];
    process_supply_chain($routes);
}

main();
?>