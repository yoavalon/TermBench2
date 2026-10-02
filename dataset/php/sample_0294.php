<?php

class Graph {
    public $edges = [];

    public function add_edge($from_node, $to_node, $weight) {
        if (array_key_exists($from_node, $this->edges)) {
            $this->edges[$from_node][] = [$to_node, $weight];
        } else {
            $this->edges[$from_node] = [[$to_node, $weight]];
        }
    }
}

class Dijkstra {
    private $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_shortest_path($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->edges), INF);
        $distances[$start] = 0;
        $priority_queue = [[0, $start]];
        $visited = [];

        while (!empty($priority_queue)) {
            usort($priority_queue, function($a, $b) {
                return $a[0] <=> $b[0];
            });
            list($current_distance, $current_node) = array_shift($priority_queue);

            if (in_array($current_node, $visited)) {
                continue;
            }

            $visited[] = $current_node;

            if ($current_node == $end) {
                return $distances[$end];
            }

            if (array_key_exists($current_node, $this->graph->edges)) {
                foreach ($this->graph->edges[$current_node] as $neighbor) {
                    list($to_node, $weight) = $neighbor;
                    $distance = $current_distance + $weight;
                    if ($distance < $distances[$to_node]) {
                        $distances[$to_node] = $distance;
                        $priority_queue[] = [$distance, $to_node];
                    }
                }
            }
        }

        return INF;
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('A', 'C', 4);
    $graph->add_edge('C', 'D', 1);
    $graph->add_edge('A', 'D', 7);
    $dijkstra = new Dijkstra($graph);
    $shortest_path_length = $dijkstra->find_shortest_path('A', 'D');
    echo 'Shortest path length from A to D: ' . $shortest_path_length;
}

main();