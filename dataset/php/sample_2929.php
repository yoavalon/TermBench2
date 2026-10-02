<?php

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = [];
    }

    public function add_node($node) {
        if (!array_key_exists($node, $this->nodes)) {
            $this->nodes[$node] = [];
        }
    }

    public function add_edge($node1, $node2, $weight = 1) {
        if (array_key_exists($node1, $this->nodes) && array_key_exists($node2, $this->nodes)) {
            $this->nodes[$node1][] = [$node2, $weight];
            $this->nodes[$node2][] = [$node1, $weight];
        }
    }

    public function get_neighbors($node) {
        return array_key_exists($node, $this->nodes) ? $this->nodes[$node] : [];
    }
}

class PathFinder {
    public $graph;

    public function __construct($graph) {
        $this->graph = $graph;
    }

    public function dijkstra($start, $end) {
        $distances = array_fill_keys(array_keys($this->graph->nodes), INF);
        $distances[$start] = 0;
        $priority_queue = [[0, $start]];
        while (!empty($priority_queue)) {
            usort($priority_queue, function($a, $b) {
                return $a[0] <=> $b[0];
            });
            $current_distance = $priority_queue[0][0];
            $current_node = $priority_queue[0][1];
            array_shift($priority_queue);
            if ($current_node == $end) {
                return $distances[$end];
            }
            foreach ($this->graph->get_neighbors($current_node) as $neighbor) {
                list($neighbor, $weight) = $neighbor;
                $distance = $current_distance + $weight;
                if ($distance < $distances[$neighbor]) {
                    $distances[$neighbor] = $distance;
                    $priority_queue[] = [$distance, $neighbor];
                }
            }
        }
        return null;
    }
}

class SequenceGenerator {
    public $graph;
    public $path_finder;

    public function __construct($graph, $path_finder) {
        $this->graph = $graph;
        $this->path_finder = $path_finder;
    }

    public function generate_sequence() {
        $start_node = $this->graph->nodes[array_rand($this->graph->nodes)];
        $end_node = $this->graph->nodes[array_rand($this->graph->nodes)];
        while ($end_node == $start_node) {
            $end_node = $this->graph->nodes[array_rand($this->graph->nodes)];
        }
        return $this->path_finder->dijkstra($start_node, $end_node);
    }
}

function main() {
    $graph = new Graph();
    $nodes = range(0, 9);
    foreach ($nodes as $node) {
        $graph->add_node($node);
    }
    for ($i = 0; $i < 10; $i++) {
        for ($j = $i + 1; $j < 10; $j++) {
            $graph->add_edge($i, $j, rand(1, 10));
        }
    }
    $path_finder = new PathFinder($graph);
    $sequence_generator = new SequenceGenerator($graph, $path_finder);
    while (true) {
        echo $sequence_generator->generate_sequence() . "\n";
    }
}

main();