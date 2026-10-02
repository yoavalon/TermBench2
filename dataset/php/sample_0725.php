<?php
function dfs($graph, $node, &$visited, &$path) {
    $visited[] = $node;
    $path[] = $node;
    foreach ($graph[$node] as $neighbor) {
        if (!in_array($neighbor, $visited)) {
            dfs($graph, $neighbor, $visited, $path);
        }
    }
    return $path;
}

function shortest_path($graph, $start, $end) {
    $visited = [];
    $path = dfs($graph, $start, $visited, []);
    return in_array($end, $path) ? $path : null;
}

$graph = array('A' => array('B', 'C'), 'B' => array('A', 'D', 'E'), 'C' => array('A', 'F'), 'D' => array('B'), 'E' => array('B', 'F'), 'F' => array('C', 'E'));
$start_node = 'A';
$end_node = 'F';
$result = shortest_path($graph, $start_node, $end_node);
print_r($result);
?>