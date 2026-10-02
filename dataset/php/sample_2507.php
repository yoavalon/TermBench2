<?php

function bfs($graph, $start, $end) {
    $queue = new SplQueue();
    $queue->enqueue([$start, [$start]]);
    $visited = [];
    while (!$queue->isEmpty()) {
        list($node, $path) = $queue->dequeue();
        $visited[$node] = true;
        if ($node == $end) {
            return $path;
        }
        foreach ($graph[$node] as $neighbor) {
            if (!isset($visited[$neighbor])) {
                $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
            }
        }
    }
    return [];
}

function shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
$start_node = 'A';
$end_node = 'F';
$result = shortest_path($graph, $start_node, $end_node);
print_r($result);

?>