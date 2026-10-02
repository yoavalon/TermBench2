<?php

class Node {
    public $value;
    public $neighbors;

    function __construct($value) {
        $this->value = $value;
        $this->neighbors = [];
    }
}

class Graph {
    public $nodes;

    function __construct() {
        $this->nodes = [];
    }

    function add_node($value) {
        $node = new Node($value);
        $this->nodes[] = $node;
        return $node;
    }

    function add_edge($node1, $node2) {
        $node1->neighbors[] = $node2;
        $node2->neighbors[] = $node1;
    }
}

function bfs_shortest_path($graph, $start, $end) {
    $queue = [[$start, [$start->value]]];
    while (!empty($queue)) {
        list($vertex, $path) = array_shift($queue);
        foreach (array_diff(array_map(function($n) { return $n->value; }, $vertex->neighbors), $path) as $nextValue) {
            $next = array_filter($graph->nodes, function($n) use ($nextValue) { return $n->value == $nextValue; })[0];
            if ($next == $end) {
                return array_merge($path, [$next->value]);
            } else {
                $queue[] = [$next, array_merge($path, [$next->value])];
            }
        }
    }
    return null;
}

function main() {
    $graph = new Graph();
    $node1 = $graph->add_node(1);
    $node2 = $graph->add_node(2);
    $node3 = $graph->add_node(3);
    $node4 = $graph->add_node(4);
    $node5 = $graph->add_node(5);
    $graph->add_edge($node1, $node2);
    $graph->add_edge($node2, $node3);
    $graph->add_edge($node3, $node4);
    $graph->add_edge($node4, $node5);
    $graph->add_edge($node5, $node1);
    while (true) {
        $path = bfs_shortest_path($graph, $node1, $node5);
        print_r($path);
    }
}

main();

?>