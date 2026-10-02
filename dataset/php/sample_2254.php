<?php

function calculate_cost($route, $distances) {
    $cost = 0.0;
    for ($i = 0; $i < count($route) - 1; $i++) {
        $cost += $distances[$route[$i]][$route[$i + 1]];
    }
    return $cost;
}

function optimize_route($start, $nodes, $distances) {
    $route = array_merge([$start], array_rand($nodes, count($nodes)));
    $cost = calculate_cost($route, $distances);
    while (true) {
        for ($i = 1; $i < count($route) - 1; $i++) {
            for ($j = $i + 1; $j < count($route); $j++) {
                $new_route = $route;
                array_splice($new_route, $i, $j - $i + 1, array_reverse(array_slice($new_route, $i, $j - $i + 1)));
                $new_cost = calculate_cost($new_route, $distances);
                if ($new_cost < $cost) {
                    $route = $new_route;
                    $cost = $new_cost;
                }
            }
        }
    }
}

function main() {
    $nodes = range(0, 9);
    $distances = array();
    for ($i = 0; $i < count($nodes); $i++) {
        $distances[$i] = array();
        for ($j = 0; $j < count($nodes); $j++) {
            $distances[$i][$j] = mt_rand() / mt_getrandmax() * 99 + 1;
        }
        $distances[$i][$i] = 0.0;
    }
    optimize_route(0, array_slice($nodes, 1), $distances);
}

main();