<?php
function dijkstra($graph, $start, $end) {
    $distances = array_fill_keys(array_keys($graph), INF);
    $distances[$start] = 0;
    $unvisited = array_keys($graph);
    $current = $start;
    while ($current != $end && !empty($unvisited)) {
        foreach ($graph[$current] as $neighbor => $weight) {
            $distance = $distances[$current] + $weight;
            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
            }
        }
        $key = array_search($current, $unvisited);
        if ($key !== false) {
            unset($unvisited[$key]);
        }
        if (empty($unvisited)) {
            break;
        }
        $current = array_reduce($unvisited, function($carry, $item) use ($distances) {
            return $distances[$carry] < $distances[$item] ? $carry : $item;
        });
        if (!in_array($current, $unvisited)) {
            break;
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
    echo dijkstra($graph, $start, $end);
}

main();