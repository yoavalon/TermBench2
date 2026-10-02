<?php

function dijkstra($graph, $start, $end) {
    $queue = [[0, $start]];
    $visited = [];
    while (!empty($queue)) {
        sort($queue);
        $cost = $queue[0][0];
        $node = $queue[0][1];
        array_shift($queue);
        if ($node == $end) {
            return $cost;
        }
        if (in_array($node, $visited)) {
            continue;
        }
        $visited[] = $node;
        if (isset($graph[$node])) {
            foreach ($graph[$node] as $neighbor) {
                $queue[] = [$cost + $neighbor[1], $neighbor[0]];
            }
        }
    }
    return INF;
}

function shortest_path($graph, $start, $end) {
    return dijkstra($graph, $start, $end);
}

function main() {
    $graph = [
        'A' => [['B', 1], ['C', 4]],
        'B' => [['A', 1], ['C', 2], ['D', 5]],
        'C' => [['A', 4], ['B', 2], ['D', 1]],
        'D' => [['B', 5], ['C', 1]]
    ];
    $start = 'A';
    $end = 'D';
    echo shortest_path($graph, $start, $end);
}

main();