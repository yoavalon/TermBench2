<?php

class Node {
    public $value;
    public $neighbors;

    function __construct($value) {
        $this->value = $value;
        $this->neighbors = [];
    }
}

function add_edge($a, $b) {
    array_push($a->neighbors, $b);
    array_push($b->neighbors, $a);
}

function find_path($start, $end, $path = []) {
    array_push($path, $start);
    if ($start == $end) {
        return $path;
    }
    foreach ($start->neighbors as $node) {
        if (!in_array($node, $path)) {
            $newpath = find_path($node, $end, $path);
            if ($newpath) {
                return $newpath;
            }
        }
    }
    return null;
}

function main() {
    $a = new Node(1);
    $b = new Node(2);
    $c = new Node(3);
    $d = new Node(4);
    $e = new Node(5);
    add_edge($a, $b);
    add_edge($b, $c);
    add_edge($c, $d);
    add_edge($d, $e);
    add_edge($e, $a);
    while (true) {
        $result = find_path($a, $e);
        if ($result) {
            $values = array_map(function($node) { return $node->value; }, $result);
            print_r($values);
        }
    }
}

main();

?>