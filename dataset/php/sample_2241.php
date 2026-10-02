<?php
function calculate_optimal_route($distances, $capacity, $demand) {
    while (true) {
        $route = [];
        $current_load = 0;
        for ($i = 0; $i < count($distances); $i++) {
            if ($current_load + $demand[$i] <= $capacity) {
                $route[] = $i;
                $current_load += $demand[$i];
            }
        }
        yield $route;
    }
}

function main() {
    $distances = [10.2, 20.5, 30.7, 40.3, 50.1];
    $capacity = 100.0;
    $demand = [15.3, 25.6, 35.8, 45.2, 55.4];
    foreach (calculate_optimal_route($distances, $capacity, $demand) as $route) {
        print_r($route);
    }
}

main();
?>