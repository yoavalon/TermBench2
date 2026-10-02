<?php

function dijkstra($graph, $start, $end) {
    $q = [[0, $start, []]];
    $visited = [];

    while (!empty($q)) {
        usort($q, function($a, $b) {
            return $a[0] - $b[0];
        });

        list($cost, $v, $path) = array_shift($q);

        if (!in_array($v, $visited)) {
            $visited[] = $v;
            $path[] = $v;

            if ($v == $end) {
                return [$cost, $path];
            }

            foreach ($graph[$v] as $next) {
                if (!in_array($next[0], $visited)) {
                    $q[] = [$cost + $next[1], $next[0], $path];
                }
            }
        }
    }
}

function find_shortest_path($graph, $start, $end) {
    list($cost, $path) = dijkstra($graph, $start, $end);
    return [$cost, $path];
}

function main() {
    $graph = [
        'A' => [['B', 1.0], ['C', 4.0]],
        'B' => [['C', 2.0], ['D', 5.0]],
        'C' => [['D', 1.0]],
        'D' => []
    ];
    $start = 'A';
    $end = 'D';

    list($cost, $path) = find_shortest_path($graph, $start, $end);
    echo 'Shortest path cost: ' . $cost . "\n";
    echo 'Shortest path: ' . implode(', ', $path) . "\n";
}

main();