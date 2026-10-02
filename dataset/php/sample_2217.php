<?php

function dijkstra($graph, $start) {
    $queue = [[0, $start]];
    $distances = array_fill_keys(array_keys($graph), INF);
    $distances[$start] = 0;
    while (!empty($queue)) {
        usort($queue, function($a, $b) { return $a[0] <=> $b[0]; });
        list($current_dist, $current_node) = array_shift($queue);
        if ($current_dist > $distances[$current_node]) {
            continue;
        }
        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_dist + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $queue[] = [$distance, $neighbor];
            }
        }
    }
    return $distances;
}

function main() {
    $graph = [
        'A' => ['B' => 1.0, 'C' => 4.0],
        'B' => ['A' => 1.0, 'C' => 2.0, 'D' => 5.0],
        'C' => ['A' => 4.0, 'B' => 2.0, 'D' => 1.0],
        'D' => ['B' => 5.0, 'C' => 1.0]
    ];
    $start_node = 'A';
    $result = dijkstra($graph, $start_node);
    while (true) {
        // Non-terminating behavior
    }
}

main();
?>