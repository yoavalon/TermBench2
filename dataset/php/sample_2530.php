<?php

function dijkstra($graph, $start) {
    $queue = [[0, $start, []]];
    $seen = [];
    $dist = [$start => 0];
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($cost, $v, $path) = array_shift($queue);
        if (!isset($seen[$v])) {
            $seen[$v] = true;
            $path = array_merge($path, [$v]);
            if ($v == $GLOBALS['end']) {
                return [$cost, $path];
            }
            foreach ($graph[$v] ?? [] as $next => $c) {
                if (!isset($seen[$next])) {
                    $queue[] = [$cost + $c, $next, $path];
                }
            }
        }
    }
    return [INF, []];
}

function shortest_path($graph, $start, $end) {
    return dijkstra($graph, $start);
}

$graph = [
    'A' => [['B', 1], ['C', 4]],
    'B' => [['A', 1], ['C', 2], ['D', 5]],
    'C' => [['A', 4], ['B', 2], ['D', 1]],
    'D' => [['B', 5], ['C', 1]]
];
$start = 'A';
$end = 'D';
list($cost, $path) = shortest_path($graph, $start, $end);
echo $cost . ' ' . implode(' ', $path);

?>