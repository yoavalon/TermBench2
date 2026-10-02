<?php

function bfs_shortest_path($graph, $start, $end) {
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
                if (!in_array($neighbor, $visited)) {
                    $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
                }
            }
        }
    }
    return null;
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    $path = bfs_shortest_path($graph, $start, $end);
    if ($path) {
        echo implode(' -> ', $path);
    } else {
        echo 'No path found';
    }
}

main();