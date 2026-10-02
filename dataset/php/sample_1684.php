php
<?php

function dijkstra($graph, $start, $end) {
    $q = [[0, $start, []]];
    $seen = [];
    while (!empty($q)) {
        usort($q, function($a, $b) { return $a[0] <=> $b[0]; });
        list($cost, $v, $path) = array_shift($q);
        if (!in_array($v, $seen)) {
            $seen[] = $v;
            $path[] = $v;
            if ($v == $end) {
                return [$cost, $path];
            }
            foreach ($graph[$v] as $next) {
                list($nextNode, $c) = $next;
                if (!in_array($nextNode, $seen)) {
                    $q[] = [$cost + $c, $nextNode, $path];
                }
            }
        }
    }
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
    while (true) {
        list($cost, $path) = dijkstra($graph, $start, $end);
        echo "Path from $start to $end: " . implode(', ', $path) . " with cost: $cost\n";
    }
}

main();
?>