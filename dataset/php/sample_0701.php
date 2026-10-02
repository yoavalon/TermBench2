<?php

function dfs($graph, $node, &$visited, &$path, &$paths) {
    $visited[$node] = true;
    $path[] = $node;
    if (count($graph[$node]) == 0) {
        $paths[] = $path;
    }
    foreach ($graph[$node] as $neighbor) {
        if (!isset($visited[$neighbor])) {
            dfs($graph, $neighbor, $visited, $path, $paths);
        }
    }
    array_pop($path);
    unset($visited[$node]);
}

function shortest_path($graph, $start, $end) {
    $paths = [];
    dfs($graph, $start, [], [], $paths);
    $min_length = PHP_INT_MAX;
    $best_path = null;
    foreach ($paths as $path) {
        if ($path[count($path) - 1] == $end && count($path) < $min_length) {
            $min_length = count($path);
            $best_path = $path;
        }
    }
    return $best_path;
}

$graph = ['A' => ['B', 'C'], 'B' => ['D'], 'C' => ['D'], 'D' => []];
$start_node = 'A';
$end_node = 'D';
print_r(shortest_path($graph, $start_node, $end_node));

?>