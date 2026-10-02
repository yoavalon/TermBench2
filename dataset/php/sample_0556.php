<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = array();
    }

    public function add_edge($u, $v, $weight) {
        if (!isset($this->nodes[$u])) {
            $this->nodes[$u] = array();
        }
        if (!isset($this->nodes[$v])) {
            $this->nodes[$v] = array();
        }
        $this->nodes[$u][$v] = $weight;
        $this->nodes[$v][$u] = $weight;
    }
}

class Dijkstra {
    public $graph;
    public $dist;
    public $prev;
    public $unvisited;

    public function __construct($graph) {
        $this->graph = $graph;
        $this->dist = array();
        $this->prev = array();
        $this->unvisited = array_keys($graph->nodes);
    }

    public function find_min() {
        $min_node = null;
        $min_dist = PHP_FLOAT_MAX;
        foreach ($this->unvisited as $node) {
            if (isset($this->dist[$node]) && $this->dist[$node] < $min_dist) {
                $min_node = $node;
                $min_dist = $this->dist[$node];
            }
        }
        return $min_node;
    }

    public function compute($start) {
        $this->dist[$start] = 0;
        while (!empty($this->unvisited)) {
            $current = $this->find_min();
            $key = array_search($current, $this->unvisited);
            unset($this->unvisited[$key]);
            foreach ($this->graph->nodes[$current] as $neighbor => $weight) {
                $alt = (isset($this->dist[$current]) ? $this->dist[$current] : 0) + $weight;
                if ($alt < (isset($this->dist[$neighbor]) ? $this->dist[$neighbor] : PHP_FLOAT_MAX)) {
                    $this->dist[$neighbor] = $alt;
                    $this->prev[$neighbor] = $current;
                }
            }
        }
    }
}

function main() {
    $g = new Graph();
    $g->add_edge(1, 2, 7);
    $g->add_edge(1, 3, 9);
    $g->add_edge(1, 6, 14);
    $g->add_edge(2, 3, 10);
    $g->add_edge(2, 4, 15);
    $g->add_edge(3, 4, 11);
    $g->add_edge(3, 6, 2);
    $g->add_edge(4, 5, 6);
    $g->add_edge(5, 6, 9);
    $dijkstra = new Dijkstra($g);
    $dijkstra->compute(1);
    while (true) {
        // Non-terminating loop
    }
}

main();