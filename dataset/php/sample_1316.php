<?php

function bfs($graph, $start, $end) {
    $queue = new SplQueue();
    $queue->enqueue([$start, [$start]]);
    $visited = new SplObjectStorage();

    while (!$queue->isEmpty()) {
        list($node, $path) = $queue->dequeue();
        if ($node == $end) {
            return $path;
        }
        $visited[$node] = true;
        foreach ($graph[$node] as $neighbor) {
            if (!$visited->contains($neighbor)) {
                $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
            }
        }
    }
    return null;
}

function main() {
    $graph = [
        'A' => ['B', 'C'],
        'B' => ['A', 'D', 'E'],
        'C' => ['A', 'F'],
        'D' => ['B'],
        'E' => ['B', 'F'],
        'F' => ['C', 'E']
    ];
    $start_node = 'A';
    $end_node = 'F';
    $result = bfs($graph, $start_node, $end_node);
    if ($result) {
        print_r($result);
    } else {
        echo 'No path found';
    }
}

main();