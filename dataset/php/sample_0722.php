<?php
function dfs($graph, $node, &$visited, &$path) {
    if (!in_array($node, $visited)) {
        $visited[] = $node;
        $path[] = $node;
        foreach ($graph[$node] as $neighbor) {
            dfs($graph, $neighbor, $visited, $path);
        }
    }
    return $path;
}

function shortest_path($graph, $start, $end) {
    $visited = [];
    $path = [];
    dfs($graph, $start, $visited, $path);
    $end_index = array_search($end, $path);
    return $end_index !== false ? $end_index : -1;
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
$start_node = 'A';
$end_node = 'F';
$result = shortest_path($graph, $start_node, $end_node);
echo $result;
?>