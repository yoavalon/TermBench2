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

function find_shortest_path($graph, $start, $end) {
    $path = bfs($graph, $start, $end);
    if ($path) {
        return count($path) - 1;
    }
    return -1;
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']];
    $start = 'A';
    $end = 'F';
    echo find_shortest_path($graph, $start, $end);
}

main();
?>