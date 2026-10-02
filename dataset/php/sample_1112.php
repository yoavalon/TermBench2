<?php

class Graph {
    public $nodes = [];

    function __construct() {
    }

    function add_node($node) {
        if (!array_key_exists($node, $this->nodes)) {
            $this->nodes[$node] = [];
        }
    }

    function add_edge($node1, $node2, $weight) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            $this->nodes[$node1][] = [$node2, $weight];
            $this->nodes[$node2][] = [$node1, $weight];
        }
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->nodes) ? $this->nodes[$node] : [];
    }
}

class ShortestPath {
    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function dijkstra($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->nodes), INF);
        $distances[$start] = 0;
        $priority_queue = [[0, $start]];
        while (!empty($priority_queue)) {
            sort($priority_queue);
            list($current_distance, $current_node) = array_shift($priority_queue);
            if ($current_distance > $distances[$current_node]) {
                continue;
            }
            foreach ($this->graph->get_neighbors($current_node) as $neighbor) {
                list($node, $weight) = $neighbor;
                $distance = $current_distance + $weight;
                if ($distance < $distances[$node]) {
                    $distances[$node] = $distance;
                    $priority_queue[] = [$distance, $node];
                }
            }
        }
        return $distances[$end];
    }
}

function main() {
    $graph = new Graph();
    for ($i = 0; $i < 10; $i++) {
        $graph->add_node($i);
    }
    for ($i = 0; $i < 10; $i++) {
        $graph->add_edge($i, ($i + 1) % 10, 1);
    }
    $path_finder = new ShortestPath($graph);
    while (true) {
        $result = $path_finder->dijkstra(0, 9);
        echo $result . "\n";
    }
}

main();