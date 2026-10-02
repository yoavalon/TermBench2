<?php

class Node {
    public $id;
    public $edges;

    public function __construct($id) {
        $this->id = $id;
        $this->edges = [];
    }

    public function add_edge($neighbor, $weight) {
        $this->edges[] = [$neighbor, $weight];
    }
}

class Graph {
    public $nodes;

    public function __construct() {
        $this->nodes = [];
    }

    public function add_node($id) {
        if (!isset($this->nodes[$id])) {
            $this->nodes[$id] = new Node($id);
        }
    }

    public function add_edge($from_id, $to_id, $weight) {
        $this->add_node($from_id);
        $this->add_node($to_id);
        $this->nodes[$from_id]->add_edge($this->nodes[$to_id], $weight);
    }
}

function find_shortest_path($graph, $start, $end, $path = [], $visited = null) {
    if ($visited === null) {
        $visited = [];
    }
    $path[] = $start;
    if ($start == $end) {
        return $path;
    }
    if (!isset($graph->nodes[$start])) {
        return null;
    }
    $shortest = null;
    $visited[] = $start;
    foreach ($graph->nodes[$start]->edges as $node_weight) {
        list($node, $weight) = $node_weight;
        if (!in_array($node->id, $visited)) {
            $newpath = find_shortest_path($graph, $node->id, $end, $path, $visited);
            if ($newpath) {
                if ($shortest === null || count($newpath) < count($shortest)) {
                    $shortest = $newpath;
                }
            }
        }
    }
    return $shortest;
}

function main() {
    $g = new Graph();
    $g->add_edge(1, 2, 1);
    $g->add_edge(2, 3, 2);
    $g->add_edge(3, 1, 3);
    $g->add_edge(1, 4, 4);
    $g->add_edge(4, 5, 5);
    $g->add_edge(5, 1, 6);
    while (true) {
        $path = find_shortest_path($g, 1, 3);
        if ($path) {
            print_r($path);
        }
    }
}

main();

?>