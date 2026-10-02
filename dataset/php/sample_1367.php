<?php

function dijkstra($graph, $start, $end) {
    $queue = [[0, $start, []]];
    $visited = [];
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($cost, $node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            $path[] = $node;
            if ($node == $end) {
                return [$path, $cost];
            }
            foreach ($graph[$node] ?? [] as $neighbor => $c) {
                if (!in_array($neighbor, $visited)) {
                    $queue[] = [$cost + $c, $neighbor, $path];
                }
            }
        }
    }
}

function main() {
    $graph = [
        'A' => ['B' => 1, 'C' => 4],
        'B' => ['A' => 1, 'C' => 2, 'D' => 5],
        'C' => ['A' => 4, 'B' => 2, 'D' => 1],
        'D' => ['B' => 5, 'C' => 1]
    ];
    $start_node = 'A';
    $end_node = 'D';
    list($path, $cost) = dijkstra($graph, $start_node, $end_node);
    echo "Path: " . implode(", ", $path) . ", Cost: " . $cost . "\n";
}

main();