<?php

function dfs($graph, $start, $end, $path, &$visited) {
    $path[] = $start;
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

function shortest_path($graph, $start, $end) {
    $path = dfs($graph, $start, $end, [], $visited = []);
    return $path ? $path : [];
}

$graph = [];
$graph['A'] = ['B', 'C'];
$graph['B'] = ['C', 'D'];
$graph['C'] = ['D'];
$graph['D'] = ['E'];
$start = 'A';
$end = 'E';
$result = shortest_path($graph, $start, $end);
print_r($result);

?>