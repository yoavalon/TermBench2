<?php

function dijkstra($graph, $start, $end) {
    $queue = [];
    array_push($queue, [0, $start]);
    $distances = array_fill_keys(array_keys($graph), INF);
    $distances[$start] = 0;

    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($current_distance, $current_node) = array_shift($queue);

        if ($current_node == $end) {
            return $current_distance;
        }

        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_distance + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                array_push($queue, [$distance, $neighbor]);
            }
        }
    }

    return -1;
}

function build_graph($edges) {
    $graph = [];
    foreach ($edges as list($a, $b, $weight)) {
        if (!isset($graph[$a])) {
            $graph[$a] = [];
        }
        if (!isset($graph[$b])) {
            $graph[$b] = [];
        }
        $graph[$a][$b] = $weight;
        $graph[$b][$a] = $weight;
    }
    return $graph;
}

function main() {
    $edges = [[1, 2, 7], [1, 3, 9], [2, 3, 10], [2, 4, 15], [3, 4, 11]];
    $graph = build_graph($edges);
    echo dijkstra($graph, 1, 4);
}

main();