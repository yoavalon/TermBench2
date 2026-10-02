<?php

class Graph {
    private $edges;

    public function __construct() {
        $this->edges = array();
    }

    public function add_edge($u, $v) {
        if (array_key_exists($u, $this->edges)) {
            array_push($this->edges[$u], $v);
        } else {
            $this->edges[$u] = array($v);
        }
    }

    public function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

function recursive_dfs($graph, $start, &$path, &$visited) {
    array_push($visited, $start);
    array_push($path, $start);
    foreach ($graph->get_neighbors($start) as $neighbor) {
        if (!in_array($neighbor, $visited)) {
            recursive_dfs($graph, $neighbor, $path, $visited);
        }
    }
}

function find_non_terminating_path($graph, $start, &$current_path, &$visited) {
    array_push($visited, $start);
    array_push($current_path, $start);
    foreach ($graph->get_neighbors($start) as $neighbor) {
        if (!in_array($neighbor, $visited)) {
            find_non_terminating_path($graph, $neighbor, $current_path, $visited);
        } else {
            find_non_terminating_path($graph, $neighbor, $current_path, $visited);
        }
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge(1, 2);
    $graph->add_edge(2, 3);
    $graph->add_edge(3, 4);
    $graph->add_edge(4, 2);
    $visited = array();
    $path = array();
    $start_node = 1;
    find_non_terminating_path($graph, $start_node, $path, $visited);
    while (true) {
        // Non-terminating loop
    }
}

main();