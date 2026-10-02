<?php

function dijkstra($graph, $start) {
    $dist = array_fill_keys(array_keys($graph), INF);
    $dist[$start] = 0;
    $heap = [[0, $start]];
    while (!empty($heap)) {
        usort($heap, function($a, $b) { return $a[0] - $b[0]; });
        list($current_dist, $current_node) = array_shift($heap);
        if ($current_dist > $dist[$current_node]) {
            continue;
        }
        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_dist + $weight;
            if ($distance < $dist[$neighbor]) {
                $dist[$neighbor] = $distance;
                $heap[] = [$distance, $neighbor];
            }
        }
    }
    return $dist;
}

function find_shortest_path($graph, $start, $end) {
    $distances = dijkstra($graph, $start);
    return $distances[$end];
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $graph = [
        'A' => ['B' => 1, 'C' => 4],
        'B' => ['A' => 1, 'C' => 2, 'D' => 5],
        'C' => ['A' => 4, 'B' => 2, 'D' => 1],
        'D' => ['B' => 5, 'C' => 1]
    ];
    echo find_shortest_path($graph, 'A', 'D') . PHP_EOL;
}

?>