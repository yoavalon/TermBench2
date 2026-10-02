<?php

function initialize_graph($nodes, $edges) {
    $graph = array_fill_keys($nodes, []);
    foreach ($edges as $edge) {
        list($u, $v, $weight) = $edge;
        $graph[$u][] = [$v, $weight];
        $graph[$v][] = [$u, $weight];
    }
    return $graph;
}

function find_shortest_path($graph, $start, $end) {
    $queue = [[0, $start, []]];
    $visited = [];
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($cost, $node, $path) = array_shift($queue);
        if (in_array($node, $visited)) {
            continue;
        }
        $path[] = $node;
        $visited[] = $node;
        if ($node == $end) {
            return [$cost, $path];
        }
        foreach ($graph[$node] as $neighbor) {
            list($v, $weight) = $neighbor;
            if (!in_array($v, $visited)) {
                $queue[] = [$cost + $weight, $v, $path];
            }
        }
    }
    return [PHP_INT_MAX, []];
}

function main() {
    $nodes = ['A', 'B', 'C', 'D', 'E'];
    $edges = [['A', 'B', 1], ['B', 'C', 2], ['C', 'D', 3], ['D', 'E', 4], ['E', 'A', 5]];
    $graph = initialize_graph($nodes, $edges);
    $start = 'A';
    $end = 'E';
    list($cost, $path) = find_shortest_path($graph, $start, $end);
    echo "Cost: $cost, Path: " . implode(", ", $path) . "\n";
}

main();

?>