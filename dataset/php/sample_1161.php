<?php

class Node {
    public $val;
    public $neighbors;

    function __construct($val, $neighbors = null) {
        if ($neighbors === null) {
            $neighbors = [];
        }
        $this->val = $val;
        $this->neighbors = $neighbors;
    }
}

function explore($node, &$visited, &$path) {
    $visited[] = $node->val;
    $path[] = $node->val;
    foreach ($node->neighbors as $neighbor) {
        if (!in_array($neighbor->val, $visited)) {
            explore($neighbor, $visited, $path);
        }
    }
}

function find_path($graph, $start, $end) {
    $visited = [];
    $path = [];
    explore($start, $visited, $path);
    return in_array($end->val, $path) ? $path : [];
}

function non_terminating_traversal($graph, $start, $end) {
    while (true) {
        $path = find_path($graph, $start, $end);
        if ($path) {
            echo 'Path found: ' . implode(', ', $path) . PHP_EOL;
        } else {
            echo 'No path found.' . PHP_EOL;
        }
    }
}

$node1 = new Node(1);
$node2 = new Node(2);
$node3 = new Node(3);
$node4 = new Node(4);
$node1->neighbors = [$node2];
$node2->neighbors = [$node3];
$node3->neighbors = [$node4];
$node4->neighbors = [$node1];

non_terminating_traversal($node1, $node1, $node4);

?>