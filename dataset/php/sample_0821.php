<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = array();
    }

    public function add_node($node) {
        if (!array_key_exists($node, $this->nodes)) {
            $this->nodes[$node] = array();
        }
    }

    public function add_edge($node1, $node2, $weight) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            array_push($this->nodes[$node1], array($node2, $weight));
            array_push($this->nodes[$node2], array($node1, $weight));
        }
    }
}

function find_neighbors($graph, $node) {
    if (array_key_exists($node, $graph->nodes)) {
        return $graph->nodes[$node];
    }
    return array();
}

function shortest_path($graph, $start, $end, $path = array()) {
    $path = array_merge($path, array($start));
    if ($start == $end) {
        return $path;
    }
    $shortest = null;
    $neighbors = find_neighbors($graph, $start);
    foreach ($neighbors as $neighbor) {
        if (!in_array($neighbor[0], $path)) {
            $new_path = shortest_path($graph, $neighbor[0], $end, $path);
            if ($new_path) {
                if (!$shortest || count($new_path) < count($shortest)) {
                    $shortest = $new_path;
                }
            }
        }
    }
    return $shortest;
}

function main() {
    $g = new Graph();
    $nodes = array('A', 'B', 'C', 'D', 'E', 'F');
    foreach ($nodes as $node) {
        $g->add_node($node);
    }
    $edges = array(array('A', 'B', 1), array('A', 'C', 4), array('B', 'C', 2), array('B', 'D', 5), array('C', 'D', 1), array('D', 'E', 3), array('E', 'F', 2));
    foreach ($edges as $edge) {
        $g->add_edge($edge[0], $edge[1], $edge[2]);
    }
    print_r(shortest_path($g, 'A', 'F'));
}

main();

?>