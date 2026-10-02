<?php

function dijkstra($graph, $start) {
    $distances = array_fill_keys(array_keys($graph), INF);
    $distances[$start] = 0;
    $priority_queue = [[0, $start]];
    
    while (!empty($priority_queue)) {
        usort($priority_queue, function($a, $b) { return $a[0] <=> $b[0]; });
        list($current_distance, $current_node) = array_shift($priority_queue);
        
        if ($current_distance > $distances[$current_node]) {
            continue;
        }
        
        foreach ($graph[$current_node] as $neighbor => $weight) {
            $distance = $current_distance + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $priority_queue[] = [$distance, $neighbor];
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
    print_r($result);
}

main();

?>