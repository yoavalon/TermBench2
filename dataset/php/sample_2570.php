<?php
function calculate_optimal_routes($distance_matrix, $max_routes) {
    $num_locations = count($distance_matrix);
    $routes = [];
    for ($i = 0; $i < $num_locations; $i++) {
        for ($j = $i + 1; $j < $num_locations; $j++) {
            $routes[] = [$i, $j, $distance_matrix[$i][$j]];
        }
    }
    usort($routes, function($a, $b) {
        return $a[2] <=> $b[2];
    });
    $optimal_routes = [];
    $selected_pairs = [];
    foreach ($routes as $route) {
        if (!in_array($route[0], $selected_pairs) && !in_array($route[1], $selected_pairs)) {
            $optimal_routes[] = $route;
            $selected_pairs[] = $route[0];
            $selected_pairs[] = $route[1];
            if (count($optimal_routes) == $max_routes) {
                break;
            }
        }
    }
    return $optimal_routes;
}

function main() {
    $distance_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]];
    $max_routes = 2;
    $result = calculate_optimal_routes($distance_matrix, $max_routes);
    print_r($result);
}

main();
?>