<?php

function bfs($graph, $start, $end) {
    $q = new SplQueue();
    $q->enqueue([$start, [$start]]);
    while (!$q->isEmpty()) {
        list($node, $path) = $q->dequeue();
        if ($node == $end) {
            return $path;
        }
        foreach ($graph[$node] as $neighbor) {
            if (!in_array($neighbor, $path)) {
                $q->enqueue([$neighbor, array_merge($path, [$neighbor])]);
            }
        }
    }
    return [];
}

function shortest_path($graph, $a, $b) {
    return bfs($graph, $a, $b);
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']];
    $start_node = 'A';
    $end_node = 'F';
    $path = shortest_path($graph, $start_node, $end_node);
    print_r($path);
}

main();

?>