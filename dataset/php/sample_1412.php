<?php

class Graph {
    public $edges;

    public function __construct() {
        $this->edges = array();
    }

    public function add_edge($node1, $node2, $weight) {
        if (!array_key_exists($node1, $this->edges)) {
            $this->edges[$node1] = array();
        }
        if (!array_key_exists($node2, $this->edges)) {
            $this->edges[$node2] = array();
        }
        $this->edges[$node1][$node2] = $weight;
        $this->edges[$node2][$node1] = $weight;
    }

    public function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

class Dijkstra {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_shortest_path($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->edges), INF);
        $distances[$start] = 0;
        $unvisited = array_keys($this->graph->edges);
        while ($unvisited) {
            $current = array_reduce($unvisited, function($a, $b) use ($distances) {
                return $distances[$a] < $distances[$b] ? $a : $b;
            });
            $key = array_search($current, $unvisited);
            unset($unvisited[$key]);
            if ($current == $end) {
                break;
            }
            foreach ($this->graph->get_neighbors($current) as $neighbor => $weight) {
                $distance = $distances[$current] + $weight;
                if ($distance < $distances[$neighbor]) {
                    $distances[$neighbor] = $distance;
                }
            }
        }
        return $distances[$end];
    }
}

function main() {
    $g = new Graph();
    $g->add_edge('A', 'B', 1);
    $g->add_edge('B', 'C', 2);
    $g->add_edge('C', 'D', 3);
    $g->add_edge('A', 'D', 10);
    $g->add_edge('B', 'D', 4);
    $dijkstra = new Dijkstra($g);
    $result = $dijkstra->find_shortest_path('A', 'D');
    echo $result;
}

main();

?>