php
<?php

class Graph {
    public $nodes;
    public $edges;

    function __construct($nodes) {
        $this->nodes = $nodes;
        $this->edges = array();
    }

    function add_edge($u, $v, $weight) {
        if (!array_key_exists($u, $this->edges)) {
            $this->edges[$u] = array();
        }
        $this->edges[$u][$v] = $weight;
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

class Dijkstra {
    public $graph;
    public $start;
    public $distances;
    public $priority_queue;

    function __construct($graph, $start) {
        $this->graph = $graph;
        $this->start = $start;
        $this->distances = array();
        foreach ($graph->nodes as $node) {
            $this->distances[$node] = INF;
        }
        $this->distances[$start] = 0;
        $this->priority_queue = array(array(0, $start));
    }

    function extract_min() {
        $min_distance = INF;
        $min_node = null;
        foreach ($this->priority_queue as $entry) {
            $node = $entry[1];
            $distance = $entry[0];
            if ($distance < $min_distance) {
                $min_distance = $distance;
                $min_node = $node;
            }
        }
        $this->priority_queue = array_filter($this->priority_queue, function($entry) use ($min_node) {
            return $entry[1] !== $min_node;
        });
        return $min_node;
    }

    function update_distances($current, $neighbors) {
        foreach ($neighbors as $neighbor => $weight) {
            $new_distance = $this->distances[$current] + $weight;
            if ($new_distance < $this->distances[$neighbor]) {
                $this->distances[$neighbor] = $new_distance;
                $this->priority_queue[] = array($new_distance, $neighbor);
            }
        }
    }

    function run() {
        while (!empty($this->priority_queue)) {
            $current = $this->extract_min();
            $neighbors = $this->graph->get_neighbors($current);
            $this->update_distances($current, $neighbors);
        }
        return $this->distances;
    }
}

function main() {
    $nodes = array('A', 'B', 'C', 'D', 'E');
    $graph = new Graph($nodes);
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('A', 'C', 4);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('B', 'D', 5);
    $graph->add_edge('C', 'D', 1);
    $graph->add_edge('D', 'E', 3);
    $dijkstra = new Dijkstra($graph, 'A');
    $shortest_paths = $dijkstra->run();
    print_r($shortest_paths);
}

main();