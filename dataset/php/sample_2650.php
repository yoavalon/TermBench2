<?php

class Graph {
    public $nodes = [];

    public function __construct() {
        $this->nodes = [];
    }

    public function add_edge($u, $v, $weight) {
        if (array_key_exists($u, $this->nodes)) {
            $this->nodes[$u][] = array($v, $weight);
        } else {
            $this->nodes[$u] = array(array($v, $weight));
        }
    }

    public function get_neighbors($node) {
        return isset($this->nodes[$node]) ? $this->nodes[$node] : [];
    }
}

function dijkstra($graph, $start, $end) {
    $queue = array(array(0, $start, array()));
    $visited = array();
    while (!empty($queue)) {
        usort($queue, function($a, $b) { return $a[0] - $b[0]; });
        list($cost, $node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            $path[] = $node;
            if ($node == $end) {
                return array($cost, $path);
            }
            foreach ($graph->get_neighbors($node) as $neighbor) {
                list($v, $weight) = $neighbor;
                if (!in_array($v, $visited)) {
                    $queue[] = array($cost + $weight, $v, $path);
                }
            }
        }
    }
    return array(INF, array());
}

function main() {
    $graph = new Graph();
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('A', 'C', 4);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('B', 'D', 5);
    $graph->add_edge('C', 'D', 1);
    list($cost, $path) = dijkstra($graph, 'A', 'D');
    echo "Cost: " . $cost . ", Path: " . implode(", ", $path);
}

main();

?>