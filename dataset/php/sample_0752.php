<?php

function dfs($graph, $start, $end, $path, &$visited) {
    array_push($path, $start);
    $visited[$start] = true;
    if ($start == $end) {
        return $path;
    }
    foreach ($graph[$start] as $neighbor) {
        if (!isset($visited[$neighbor])) {
            $result = dfs($graph, $neighbor, $end, $path, $visited);
            if ($result) {
                return $result;
            }
        }
    }
    return null;
}

function find_shortest_path($graph, $start, $end) {
    return dfs($graph, $start, $end, [], []);
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
$path = find_shortest_path($graph, 'A', 'F');
if ($path) {
    echo 'Path found: ' . implode(', ', $path);
} else {
    echo 'No path found';
}

?>