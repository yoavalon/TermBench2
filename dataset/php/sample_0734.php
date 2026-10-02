<?php

function optimize_route($routes, $start, $end, &$visited = null, &$path = null) {
    if ($visited === null) {
        $visited = [];
    }
    if ($path === null) {
        $path = [];
    }
    $visited[] = $start;
    $path[] = $start;
    if ($start == $end) {
        return $path;
    }
    foreach ($routes[$start] ?? [] as $neighbor => $distance) {
        if (!in_array($neighbor, $visited)) {
            $result = optimize_route($routes, $neighbor, $end, $visited, $path);
            if ($result !== null) {
                return $result;
            }
        }
    }
    return null;
}

function main() {
    $routes = ['A' => ['B' => 10, 'C' => 15], 'B' => ['C' => 35, 'D' => 25], 'C' => ['D' => 30], 'D' => []];
    $start = 'A';
    $end = 'D';
    $optimal_path = optimize_route($routes, $start, $end);
    print_r($optimal_path);
}

main();

?>