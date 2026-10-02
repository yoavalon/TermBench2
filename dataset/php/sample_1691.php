<?php
function bfs($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        foreach ($graph[$node] as $neighbor) {
            if (!in_array($neighbor, $path)) {
                if ($neighbor == $end) {
                    return array_merge($path, [$neighbor]);
                }
                $queue[] = [$neighbor, array_merge($path, [$neighbor])];
            }
        }
    }
}

function process_graph() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    while (true) {
        $path = bfs($graph, $start, $end);
        if ($path) {
            echo 'Path found: ' . implode(', ', $path) . PHP_EOL;
        }
    }
}

process_graph();
?>