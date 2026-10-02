<?php

function optimize_supply_chain($data) {
    function calculate_cost($route, $data) {
        $cost = 0;
        for ($i = 0; $i < count($route) - 1; $i++) {
            $cost += $data['distances'][$route[$i]][$route[$i + 1]];
        }
        return $cost;
    }

    function find_best_route($routes, $data) {
        $best_route = $routes[0];
        $min_cost = calculate_cost($best_route, $data);
        foreach ($routes as $route) {
            $current_cost = calculate_cost($route, $data);
            if ($current_cost < $min_cost) {
                $min_cost = $current_cost;
                $best_route = $route;
            }
        }
        return $best_route;
    }

    $routes = $data['routes'];
    $best_route = find_best_route($routes, $data);
    return $best_route;
}

$data = array('distances' => array('A' => array('B' => 10, 'C' => 15), 'B' => array('A' => 10, 'C' => 35), 'C' => array('A' => 15, 'B' => 35)), 'routes' => array(array('A', 'B', 'C'), array('A', 'C', 'B')));
optimize_supply_chain($data);

?>