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
    return null;
}

function shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    $path = shortest_path($graph, $start, $end);
    if ($path) {
        echo 'Shortest path: ' . implode(', ', $path) . PHP_EOL;
    } else {
        echo 'No path found' . PHP_EOL;
    }
}

main();