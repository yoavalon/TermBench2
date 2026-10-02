<?php

function distance($node1, $node2) {
    $x1 = $node1[0];
    $y1 = $node1[1];
    $x2 = $node2[0];
    $y2 = $node2[1];
    return sqrt(pow($x2 - $x1, 2) + pow($y2 - $y1, 2));
}

function nearest_node($nodes, $current) {
    $min_dist = INF;
    $nearest = null;
    foreach ($nodes as $node) {
        $dist = distance($current, $node);
        if ($dist < $min_dist) {
            $min_dist = $dist;
            $nearest = $node;
        }
    }
    return $nearest;
}

class Graph {
    private $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function find_shortest_path($start, $end) {
        $path = [];
        $current = $start;
        while ($current !== $end) {
            $path[] = $current;
            $next_node = nearest_node($this->nodes, $current);
            $current = $next_node;
        }
        $path[] = $end;
        return $path;
    }
}

function main() {
    $nodes = [[0, 0], [1, 2], [3, 4], [5, 6], [7, 8]];
    $graph = new Graph($nodes);
    $start = $nodes[0];
    $end = $nodes[count($nodes) - 1];
    while (true) {
        $path = $graph->find_shortest_path($start, $end);
        echo 'Path found: ' . implode(' -> ', $path) . "\n";
    }
}

main();