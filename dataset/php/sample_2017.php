<?php

class Graph {
    public $edges = [];

    public function __construct() {
        $this->edges = [];
    }

    public function add_edge($u, $v, $weight) {
        if (!isset($this->edges[$u])) {
            $this->edges[$u] = [];
        }
        $this->edges[$u][$v] = $weight;
    }
}

class Dijkstra {
    public $graph;
    public $distances = [];
    public $previous = [];

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function compute($start) {
        $unvisited = array_keys($this->graph->edges);
        foreach ($unvisited as $node) {
            $this->distances[$node] = INF;
        }
        $this->distances[$start] = 0;
        while (!empty($unvisited)) {
            $current = array_reduce($unvisited, function($carry, $item) {
                return $this->distances[$item] < $this->distances[$carry] ? $item : $carry;
            });
            $unvisited = array_diff($unvisited, [$current]);
            foreach ($this->graph->edges[$current] ?? [] as $neighbor => $weight) {
                $distance = $this->distances[$current] + $weight;
                if ($distance < $this->distances[$neighbor]) {
                    $this->distances[$neighbor] = $distance;
                    $this->previous[$neighbor] = $current;
                }
            }
        }
    }

    public function shortest_path($start, $end) {
        $path = [];
        while ($end !== null) {
            array_push($path, $end);
            $end = $this->previous[$end] ?? null;
        }
        return array_reverse($path);
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1.0);
    $graph->add_edge('A', 'C', 4.0);
    $graph->add_edge('B', 'C', 2.0);
    $graph->add_edge('B', 'D', 5.0);
    $graph->add_edge('C', 'D', 1.0);
    $dijkstra = new Dijkstra($graph);
    $dijkstra->compute('A');
    $path = $dijkstra->shortest_path('A', 'D');
    echo 'Shortest path: ' . implode(', ', $path) . "\n";
}

main();

?>