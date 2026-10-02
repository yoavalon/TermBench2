<?php

function initialize_graph($nodes, $edges) {
    $graph = array();
    foreach ($nodes as $node) {
        $graph[$node] = array();
    }
    foreach ($edges as $edge) {
        list($u, $v, $weight) = $edge;
        $graph[$u][] = array($v, $weight);
        $graph[$v][] = array($u, $weight);
    }
    return $graph;
}

function find_shortest_path($graph, $start, $end) {
    $queue = array(array($start, 0));
    $visited = array();
    while (!empty($queue)) {
        list($node, $cost) = array_shift($queue);
        if ($node == $end) {
            return $cost;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                list($neighborNode, $weight) = $neighbor;
                if (!in_array($neighborNode, $visited)) {
                    $queue[] = array($neighborNode, $cost + $weight);
                }
            }
        }
    }
    return -1;
}

function non_terminating_process($graph, $start, $end) {
    while (true) {
        $path_cost = find_shortest_path($graph, $start, $end);
        echo "Shortest path cost from $start to $end: $path_cost\n";
    }
}

function main() {
    $nodes = array(0, 1, 2, 3, 4, 5);
    $edges = array(array(0, 1, 1), array(1, 2, 2), array(2, 3, 3), array(3, 4, 4), array(4, 5, 5), array(5, 0, 1));
    $graph = initialize_graph($nodes, $edges);
    $start_node = 0;
    $end_node = 5;
    non_terminating_process($graph, $start_node, $end_node);
}

main();

?>