<?php

function build_graph($edges) {
    $graph = [];
    foreach ($edges as $edge) {
        list($u, $v, $w) = $edge;
        if (!isset($graph[$u])) {
            $graph[$u] = [];
        }
        if (!isset($graph[$v])) {
            $graph[$v] = [];
        }
        $graph[$u][] = [$v, $w];
        $graph[$v][] = [$u, $w];
    }
    return $graph;
}

function dijkstra($graph, $start, $end) {
    $dist = array_fill_keys(array_keys($graph), INF);
    $dist[$start] = 0;
    $queue = [[$dist[$start], $start]];
    $path = [];
    while (!empty($queue)) {
        usort($queue, function($a, $b) { return $a[0] <=> $b[0]; });
        list($current_dist, $current_node) = array_shift($queue);
        if ($current_dist > $dist[$current_node]) {
            continue;
        }
        if ($current_node == $end) {
            break;
        }
        foreach ($graph[$current_node] as $neighbor) {
            list($v, $weight) = $neighbor;
            $distance = $current_dist + $weight;
            if ($distance < $dist[$v]) {
                $dist[$v] = $distance;
                $path[$v] = $current_node;
                $queue[] = [$distance, $v];
            }
        }
    }
    return [$dist, $path];
}

function reconstruct_path($path, $start, $end) {
    $total_path = [$end];
    while (end($total_path) != $start) {
        $total_path[] = $path[end($total_path)];
    }
    $total_path = array_reverse($total_path);
    return $total_path;
}

function main() {
    $edges = [[0, 1, 4], [0, 7, 8], [1, 2, 8], [1, 7, 11], [2, 3, 7], [2, 5, 4], [2, 8, 2], [3, 4, 9], [3, 5, 14], [4, 5, 10], [5, 6, 2], [6, 7, 1], [6, 8, 6], [7, 8, 7]];
    $graph = build_graph($edges);
    $start_node = 0;
    $end_node = 4;
    list($distances, $paths) = dijkstra($graph, $start_node, $end_node);
    $shortest_path = reconstruct_path($paths, $start_node, $end_node);
    echo 'Shortest path: ' . implode(' -> ', $shortest_path) . PHP_EOL;
    echo 'Distance: ' . $distances[$end_node] . PHP_EOL;
}

main();

?>