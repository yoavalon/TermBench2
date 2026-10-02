<?php
function dijkstra($graph, $start, $end) {
    $dist = array_fill_keys(array_keys($graph), INF);
    $dist[$start] = 0;
    $queue = [[0, $start]];
    while (!empty($queue)) {
        usort($queue, function($a, $b) { return $a[0] <=> $b[0]; });
        list($current_dist, $current_node) = array_shift($queue);
        if ($current_dist > $dist[$current_node]) {
            continue;
        }
        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_dist + $weight;
            if ($distance < $dist[$neighbor]) {
                $dist[$neighbor] = $distance;
                $queue[] = [$distance, $neighbor];
            }
        }
    }
    return $dist[$end];
}

function main() {
    $graph = [
        'A' => ['B' => 1, 'C' => 4],
        'B' => ['A' => 1, 'C' => 2, 'D' => 5],
        'C' => ['A' => 4, 'B' => 2, 'D' => 1],
        'D' => ['B' => 5, 'C' => 1]
    ];
    $start = 'A';
    $end = 'D';
    $result = dijkstra($graph, $start, $end);
    echo $result;
}

main();
?>