<?php

class Graph {
    public $nodes;

    function __construct() {
        $this->nodes = array();
    }

    function add_node($node) {
        if (!array_key_exists($node, $this->nodes)) {
            $this->nodes[$node] = array();
        }
    }

    function add_edge($from_node, $to_node, $weight) {
        if (array_key_exists($from_node, $this->nodes)) {
            $this->nodes[$from_node][] = array($to_node, $weight);
        }
    }
}

function dijkstra($graph, $start, $end) {
    $distances = array_fill_keys(array_keys($graph->nodes), INF);
    $distances[$start] = 0;
    $priority_queue = array(array(0, $start));

    while (!empty($priority_queue)) {
        usort($priority_queue, function($a, $b) {
            return $a[0] - $b[0];
        });
        list($current_distance, $current_node) = array_shift($priority_queue);

        if ($current_distance > $distances[$current_node]) {
            continue;
        }

        foreach ($graph->nodes[$current_node] as $neighbor_weight) {
            list($neighbor, $weight) = $neighbor_weight;
            $distance = $current_distance + $weight;

            if ($distance < $distances[$neighbor]) {
                $distances[$neighbor] = $distance;
                $priority_queue[] = array($distance, $neighbor);
            }
        }
    }

    return $distances[$end];
}

function main() {
    $graph = new Graph();
    $graph->add_node(1);
    $graph->add_node(2);
    $graph->add_node(3);
    $graph->add_node(4);
    $graph->add_edge(1, 2, 10);
    $graph->add_edge(1, 3, 15);
    $graph->add_edge(2, 3, 7);
    $graph->add_edge(2, 4, 12);
    $graph->add_edge(3, 4, 10);
    echo dijkstra($graph, 1, 4);
}

main();
?>