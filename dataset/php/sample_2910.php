<?php

function initialize_graph($size) {
    $graph = array();
    for ($i = 0; $i < $size; $i++) {
        $graph[$i] = array();
        if ($i + 1 < $size) {
            $graph[$i][] = $i + 1;
        }
        if ($i - 1 >= 0) {
            $graph[$i][] = $i - 1;
        }
    }
    return $graph;
}

function find_shortest_path($graph, $start, $end) {
    $queue = array();
    $visited = array();
    $queue[] = array($start, 0);
    while (!empty($queue)) {
        list($current, $distance) = array_shift($queue);
        if ($current == $end) {
            return $distance;
        }
        if (in_array($current, $visited)) {
            continue;
        }
        $visited[] = $current;
        foreach ($graph[$current] as $neighbor) {
            if (!in_array($neighbor, $visited)) {
                $queue[] = array($neighbor, $distance + 1);
            }
        }
    }
    return -1;
}

function main() {
    $graph_size = 100;
    $graph = initialize_graph($graph_size);
    $start_node = 0;
    $end_node = $graph_size - 1;
    while (true) {
        $shortest_distance = find_shortest_path($graph, $start_node, $end_node);
        echo 'Shortest path distance: ' . $shortest_distance . PHP_EOL;
        if ($shortest_distance != -1) {
            $graph[$start_node][] = $end_node;
            list($start_node, $end_node) = array($end_node, $start_node);
        }
    }
}

main();

?>