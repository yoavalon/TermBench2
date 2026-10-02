php
<?php

function bfs($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        foreach ($graph[$node] as $neighbor) {
            if ($neighbor == $end) {
                return array_merge($path, [$neighbor]);
            } elseif (!in_array($neighbor, $path)) {
                $queue[] = [$neighbor, array_merge($path, [$neighbor])];
            }
        }
    }
    return null;
}

function find_shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    $path = find_shortest_path($graph, $start, $end);
    if ($path) {
        echo implode(' -> ', $path);
    } else {
        echo 'No path found';
    }
}

main();