php
<?php

function bfs($graph, $start, $end) {
    $queue = new SplQueue();
    $queue->enqueue([$start, [$start]]);
    $visited = [];

    while (!$queue->isEmpty()) {
        list($node, $path) = $queue->dequeue();
        if ($node == $end) {
            return $path;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
            }
        }
    }
    return [];
}

function shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

$graph = [
    'A' => ['B', 'C'],
    'B' => ['D', 'E'],
    'C' => ['F'],
    'D' => [],
    'E' => ['F'],
    'F' => []
];
$start = 'A';
$end = 'F';
print_r(shortest_path($graph, $start, $end));

?>