<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = array();
    }

    public function add_node($node) {
        $this->nodes[$node] = array();
    }

    public function add_edge($node1, $node2) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            array_push($this->nodes[$node1], $node2);
            array_push($this->nodes[$node2], $node1);
        }
    }
}

class PathFinder {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_path($start, $end, $path = array()) {
        $path = array_merge($path, array($start));
        if ($start == $end) {
            return $path;
        }
        if (!array_key_exists($start, $this->graph->nodes)) {
            return null;
        }
        foreach ($this->graph->nodes[$start] as $node) {
            if (!in_array($node, $path)) {
                $newpath = $this->find_path($node, $end, $path);
                if ($newpath) {
                    return $newpath;
                }
            }
        }
        return null;
    }
}

function main() {
    $g = new Graph();
    $nodes = array('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H');
    foreach ($nodes as $node) {
        $g->add_node($node);
    }
    $edges = array(
        array('A', 'B'), array('A', 'C'), array('B', 'D'), array('B', 'E'),
        array('C', 'F'), array('C', 'G'), array('D', 'H'), array('E', 'H'),
        array('F', 'H'), array('G', 'H')
    );
    foreach ($edges as $edge) {
        $g->add_edge($edge[0], $edge[1]);
    }
    $pf = new PathFinder($g);
    while (true) {
        $path = $pf->find_path('A', 'H');
        if ($path) {
            print_r($path);
        } else {
            echo 'No path found' . PHP_EOL;
        }
    }
}

main();