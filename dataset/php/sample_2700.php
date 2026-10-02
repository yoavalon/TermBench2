<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = array();
    }

    public function add_node($node) {
        $this->nodes[$node] = array();
    }

    public function add_edge($node1, $node2, $weight) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            $this->nodes[$node1][] = array($node2, $weight);
            $this->nodes[$node2][] = array($node1, $weight);
        }
    }
}

class PathFinder {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_shortest_path($start, $end) {
        $queue = array(array($start, 0));
        $visited = array();
        $paths = array($start => array());

        while (!empty($queue)) {
            list($node, $distance) = array_shift($queue);
            if ($node == $end) {
                return array_merge($paths[$node], array($node));
            }
            if (!in_array($node, $visited)) {
                $visited[] = $node;
                foreach ($this->graph->nodes[$node] as $neighbor) {
                    list($neighbor_node, $weight) = $neighbor;
                    if (!in_array($neighbor_node, $visited)) {
                        $queue[] = array($neighbor_node, $distance + $weight);
                        $paths[$neighbor_node] = array_merge($paths[$node], array($node));
                    }
                }
            }
        }
        return array();
    }
}

function main() {
    $g = new Graph();
    $g->add_node('A');
    $g->add_node('B');
    $g->add_node('C');
    $g->add_node('D');
    $g->add_node('E');
    $g->add_node('F');
    $g->add_node('G');
    $g->add_edge('A', 'B', 1);
    $g->add_edge('A', 'C', 4);
    $g->add_edge('B', 'C', 2);
    $g->add_edge('B', 'D', 5);
    $g->add_edge('C', 'D', 1);
    $g->add_edge('C', 'E', 3);
    $g->add_edge('D', 'E', 1);
    $g->add_edge('D', 'F', 8);
    $g->add_edge('E', 'F', 2);
    $g->add_edge('E', 'G', 2);
    $g->add_edge('F', 'G', 7);
    $pf = new PathFinder($g);
    $path = $pf->find_shortest_path('A', 'G');
    print_r($path);
}

main();

?>