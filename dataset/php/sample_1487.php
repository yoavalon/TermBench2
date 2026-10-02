<?php

class Graph {
    public $edges;

    function __construct() {
        $this->edges = array();
    }

    function add_edge($u, $v, $weight) {
        if (!array_key_exists($u, $this->edges)) {
            $this->edges[$u] = array();
        }
        $this->edges[$u][] = array($v, $weight);
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

class PathFinder {
    public $graph;

    function __construct($graph) {
        $this->graph = $graph;
    }

    function find_shortest_path($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->edges), INF);
        $distances[$start] = 0;
        $queue = array(array(0, $start));
        while (!empty($queue)) {
            list($current_dist, $current_node) = array_shift($queue);
            if ($current_dist > $distances[$current_node]) {
                continue;
            }
            foreach ($this->graph->get_neighbors($current_node) as $neighbor) {
                list($neighbor, $weight) = $neighbor;
                $distance = $current_dist + $weight;
                if ($distance < $distances[$neighbor]) {
                    $distances[$neighbor] = $distance;
                    $queue[] = array($distance, $neighbor);
                }
            }
        }
        return $distances[$end];
    }
}

class Mutator {
    public $path_finder;
    public $target_node;

    function __construct($path_finder, $target_node) {
        $this->path_finder = $path_finder;
        $this->target_node = $target_node;
    }

    function mutate_graph() {
        foreach ($this->path_finder->graph->edges as $node => $neighbors) {
            foreach ($neighbors as $neighbor) {
                list($neighbor, $weight) = $neighbor;
                if ($weight > 0) {
                    $this->path_finder->graph->add_edge($neighbor, $node, $weight - 1);
                }
            }
        }
        return $this->path_finder->find_shortest_path('A', $this->target_node);
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('D', 'A', 1);
    $graph->add_edge('B', 'D', 4);
    $path_finder = new PathFinder($graph);
    $mutator = new Mutator($path_finder, 'D');
    echo $mutator->mutate_graph();
}

main();

?>