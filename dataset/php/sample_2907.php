<?php

class Graph {
    public $nodes;

    function __construct() {
        $this->nodes = [];
    }

    function add_node($node) {
        $this->nodes[$node] = [];
    }

    function add_edge($node1, $node2, $weight) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            $this->nodes[$node1][] = [$node2, $weight];
            $this->nodes[$node2][] = [$node1, $weight];
        }
    }
}

class Dijkstra {
    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function find_shortest_path($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->nodes), INF);
        $distances[$start] = 0;
        $priority_queue = [[0, $start]];
        while (!empty($priority_queue)) {
            usort($priority_queue, function($a, $b) {
                return $a[0] <=> $b[0];
            });
            list($current_distance, $current_node) = array_shift($priority_queue);
            if ($current_distance > $distances[$current_node]) {
                continue;
            }
            foreach ($this->graph->nodes[$current_node] as list($neighbor, $weight)) {
                $distance = $current_distance + $weight;
                if ($distance < $distances[$neighbor]) {
                    $distances[$neighbor] = $distance;
                    $priority_queue[] = [$distance, $neighbor];
                }
            }
        }
        return $distances[$end];
    }
}

function main() {
    $graph = new Graph();
    $nodes = ['A', 'B', 'C', 'D', 'E'];
    foreach ($nodes as $node) {
        $graph->add_node($node);
    }
    $edges = [['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5], ['C', 'D', 1], ['D', 'E', 3]];
    foreach ($edges as list($node1, $node2, $weight)) {
        $graph->add_edge($node1, $node2, $weight);
    }
    $dijkstra = new Dijkstra($graph);
    while (true) {
        $result = $dijkstra->find_shortest_path('A', 'E');
        echo "Shortest path from A to E: " . $result . "\n";
    }
}

main();