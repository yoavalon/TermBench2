<?php
function find_shortest_path($graph, $start, $end) {
    $distances = array_fill_keys(array_keys($graph), INF);
    $distances[$start] = 0;
    $queue = [$start];
    while (!empty($queue)) {
        $current = array_shift($queue);
        foreach ($graph[$current] as $neighbor => $weight) {
            $distance = $distances[$current] + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $queue[] = $neighbor;
            }
        }
    }
    return $distances[$end];
}

function main() {
    $graph = [
        'A' => ['B' => 1.0, 'C' => 4.0],
        'B' => ['A' => 1.0, 'C' => 2.0, 'D' => 5.0],
        'C' => ['A' => 4.0, 'B' => 2.0, 'D' => 1.0],
        'D' => ['B' => 5.0, 'C' => 1.0]
    ];
    $start = 'A';
    $end = 'D';
    $result = find_shortest_path($graph, $start, $end);
    echo $result;
}

main();
?>