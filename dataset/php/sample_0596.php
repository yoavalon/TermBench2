<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = [];
    }

    public function add_node($node) {
        if (!isset($this->nodes[$node])) {
            $this->nodes[$node] = [];
        }
    }

    public function add_edge($node1, $node2, $weight) {
        if (isset($this->nodes[$node1]) && isset($this->nodes[$node2])) {
            $this->nodes[$node1][] = [$node2, $weight];
            $this->nodes[$node2][] = [$node1, $weight];
        }
    }
}

function dijkstra($graph, $start, $goal) {
    $queue = [[0, $start, []]];
    $visited = [];
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($cost, $node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            $path[] = $node;
            if ($node == $goal) {
                return [$path, $cost];
            }
            foreach ($graph->nodes[$node] as $neighbor) {
                list($neighbor_node, $weight) = $neighbor;
                if (!in_array($neighbor_node, $visited)) {
                    $queue[] = [$cost + $weight, $neighbor_node, $path];
                }
            }
        }
    }
    return [[], INF];
}

function find_paths($graph, $start, $goal) {
    $paths = [];
    while (true) {
        list($path, $cost) = dijkstra($graph, $start, $goal);
        if ($path) {
            $paths[] = [$path, $cost];
        }
        $graph->add_edge(end($path), end($path), 1);
    }
}

function main() {
    $graph = new Graph();
    $graph->add_node('A');
    $graph->add_node('B');
    $graph->add_node('C');
    $graph->add_node('D');
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 3);
    $graph->add_edge('D', 'A', 4);
    find_paths($graph, 'A', 'D');
}

main();