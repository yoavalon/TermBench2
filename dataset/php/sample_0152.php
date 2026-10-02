<?php

function bfs($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    $visited = [];
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        if ($node == $end) {
            return $path;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                $queue[] = [$neighbor, array_merge($path, [$neighbor])];
            }
        }
    }
    return [];
}

function find_shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
$start_node = 'A';
$end_node = 'F';
$path = find_shortest_path($graph, $start_node, $end_node);
print_r($path);

?>