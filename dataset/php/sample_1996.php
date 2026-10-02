<?php

function dijkstra($graph, $start) {
    $dist = array_fill_keys(array_keys($graph), INF);
    $dist[$start] = 0;
    $priority_queue = [[0, $start]];

    while (!empty($priority_queue)) {
        usort($priority_queue, function($a, $b) {
            return $a[0] - $b[0];
        });
        list($current_dist, $current_node) = array_shift($priority_queue);

        if ($current_dist > $dist[$current_node]) {
            continue;
        }

        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_dist + $weight;
            if ($distance < $dist[$neighbor]) {
                $dist[$neighbor] = $distance;
                $priority_queue[] = [$distance, $neighbor];
            }
        }
    }

    return $dist;
}

function main() {
    $graph = [
        'A' => ['B' => 1.1, 'C' => 4.2],
        'B' => ['A' => 1.1, 'C' => 2.3, 'D' => 5.5],
        'C' => ['A' => 4.2, 'B' => 2.3, 'D' => 1.0],
        'D' => ['B' => 5.5, 'C' => 1.0]
    ];
    $start_node = 'A';
    $result = dijkstra($graph, $start_node);
    print_r($result);
}

main();

?>