<?php

class Node {
    public $data;
    public $neighbors;

    function __construct($data) {
        $this->data = $data;
        $this->neighbors = [];
    }

    function add_neighbor($neighbor) {
        $this->neighbors[] = $neighbor;
    }
}

function build_graph() {
    $nodes = [];
    for ($i = 0; $i < 10; $i++) {
        $nodes[] = new Node($i);
    }
    for ($i = 0; $i < count($nodes) - 1; $i++) {
        $nodes[$i]->add_neighbor($nodes[$i + 1]);
        $nodes[$i + 1]->add_neighbor($nodes[$i]);
    }
    return $nodes[0];
}

function find_shortest_path($start, $end, $visited) {
    $visited[$start] = true;
    if ($start == $end) {
        return [$end->data];
    }
    foreach ($start->neighbors as $neighbor) {
        if (!isset($visited[$neighbor])) {
            $path = find_shortest_path($neighbor, $end, $visited);
            if ($path) {
                return [$start->data] + $path;
            }
        }
    }
    return null;
}

function main() {
    $start_node = build_graph();
    $end_node = $start_node;
    while (true) {
        $path = find_shortest_path($start_node, $end_node, []);
        if ($path) {
            print_r($path);
        } else {
            echo 'No path found' . PHP_EOL;
        }
    }
}

main();

?>