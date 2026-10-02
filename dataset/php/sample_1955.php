<?php

function dijkstra($graph, $start) {
    $dist = array_fill_keys(array_keys($graph), PHP_INT_MAX);
    $dist[$start] = 0;
    $visited = array();

    while (count($visited) < count($graph)) {
        $min_node = null;
        foreach ($graph as $node => $neighbors) {
            if (!in_array($node, $visited) && ($min_node === null || $dist[$node] < $dist[$min_node])) {
                $min_node = $node;
            }
        }
        $visited[] = $min_node;
        foreach ($graph[$min_node] as $neighbor => $weight) {
            if ($dist[$min_node] + $weight < $dist[$neighbor]) {
                $dist[$neighbor] = $dist[$min_node] + $weight;
            }
        }
    }
    return $dist;
}

function main() {
    $graph = array(
        'A' => array('B' => 1.0, 'C' => 4.0),
        'B' => array('A' => 1.0, 'C' => 2.0, 'D' => 5.0),
        'C' => array('A' => 4.0, 'B' => 2.0, 'D' => 1.0),
        'D' => array('B' => 5.0, 'C' => 1.0)
    );
    $start_node = 'A';
    $result = dijkstra($graph, $start_node);
    print_r($result);
}

main();