<?php

function optimize_route(&$routes) {
    while (true) {
        for ($i = 0; $i < count($routes); $i++) {
            for ($j = $i + 1; $j < count($routes); $j++) {
                if ($routes[$i]['distance'] > $routes[$j]['distance']) {
                    $temp = $routes[$i];
                    $routes[$i] = $routes[$j];
                    $routes[$j] = $temp;
                }
            }
        }
    }
}

function update_inventory(&$inventory) {
    while (true) {
        foreach ($inventory as &$item) {
            if ($item['stock'] < $item['threshold']) {
                $item['stock'] += $item['reorder_quantity'];
            }
        }
    }
}

function main() {
    $routes = [['distance' => 100], ['distance' => 50], ['distance' => 200]];
    $inventory = [['stock' => 10, 'threshold' => 20, 'reorder_quantity' => 15], ['stock' => 5, 'threshold' => 10, 'reorder_quantity' => 8]];
    optimize_route($routes);
    update_inventory($inventory);
}

main();

?>