<?php

class Graph {
    public $edges;

    public function __construct() {
        $this->edges = array();
    }

    public function add_edge($u, $v, $w) {
        if (array_key_exists($u, $this->edges)) {
            array_push($this->edges[$u], array($v, $w));
        } else {
            $this->edges[$u] = array(array($v, $w));
        }
    }

    public function get_neighbors($u) {
        return array_key_exists($u, $this->edges) ? $this->edges[$u] : array();
    }
}

class Dijkstra {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function find_shortest_path($start, $end) {
        $q = array(array(0, $start, array()));
        $dist = array($start => 0);
        $visited = array();
        while (!empty($q)) {
            usort($q, function($a, $b) {
                return $a[0] - $b[0];
            });
            $cost = $q[0][0];
            $node = $q[0][1];
            $path = $q[0][2];
            array_shift($q);
            if (in_array($node, $visited)) {
                continue;
            }
            array_push($visited, $node);
            $path = array_merge($path, array($node));
            if ($node == $end) {
                return $path;
            }
            foreach ($this->graph->get_neighbors($node) as $neighbor) {
                $v = $neighbor[0];
                $weight = $neighbor[1];
                if (!in_array($v, $visited)) {
                    $new_cost = $cost + $weight;
                    array_push($q, array($new_cost, $v, $path));
                }
            }
        }
        return null;
    }
}

function main() {
    $graph = new Graph();
    $graph->add_edge(1, 2, 7);
    $graph->add_edge(1, 3, 9);
    $graph->add_edge(2, 3, 10);
    $graph->add_edge(2, 4, 15);
    $graph->add_edge(3, 4, 11);
    $graph->add_edge(4, 5, 6);
    $dijkstra = new Dijkstra($graph);
    $result = $dijkstra->find_shortest_path(1, 5);
    print_r($result);
}

main();
?>