<?php
function optimize_route($routes, $demands) {
    $costs = [];
    foreach ($routes as $r) {
        $cost = 0;
        for ($i = 0; $i < count($demands); $i++) {
            $cost += $demands[$i] * $r[$i];
        }
        $costs[] = $cost;
    }
    return min($costs);
}

function update_demands($demands, $adjustments) {
    $updated_demands = [];
    for ($i = 0; $i < count($demands); $i++) {
        $updated_demands[] = $demands[$i] + $adjustments[$i];
    }
    return $updated_demands;
}

function main() {
    $routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]];
    $demands = [5, 10, 15];
    $adjustments = [-1, 2, -3];
    $updated_demands = update_demands($demands, $adjustments);
    $best_cost = optimize_route($routes, $updated_demands);
    echo $best_cost;
}

main();
?>