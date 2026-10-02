<?php

class Graph {
    public $adj_list;

    function __construct() {
        $this->adj_list = array();
    }

    function add_edge($u, $v, $weight) {
        if (!array_key_exists($u, $this->adj_list)) {
            $this->adj_list[$u] = array();
        }
        if (!array_key_exists($v, $this->adj_list)) {
            $this->adj_list[$v] = array();
        }
        $this->adj_list[$u][] = array($v, $weight);
        $this->adj_list[$v][] = array($u, $weight);
    }

    function dijkstra($start) {
        $distances = array_fill_keys(array_keys($this->adj_list), INF);
        $distances[$start] = 0;
        $priority_queue = array();
        $priority_queue[] = array(0, $start);
        while (!empty($priority_queue)) {
            usort($priority_queue, function($a, $b) {
                return $a[0] - $b[0];
            });
            list($current_distance, $current_vertex) = array_shift($priority_queue);
            if ($current_distance > $distances[$current_vertex]) {
                continue;
            }
            foreach ($this->adj_list[$current_vertex] as $neighbor) {
                list($v, $weight) = $neighbor;
                $distance = $current_distance + $weight;
                if ($distance < $distances[$v]) {
                    $distances[$v] = $distance;
                    $priority_queue[] = array($distance, $v);
                }
            }
        }
        return $distances;
    }
}

class PathFinder {
    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function find_shortest_path($start, $end) {
        $distances = $this->graph->dijkstra($start);
        return $distances[$end];
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('A', 'C', 4);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('B', 'D', 5);
    $path_finder = new PathFinder($graph);
    $result = $path_finder->find_shortest_path('A', 'D');
    echo $result;
}

main();

?>