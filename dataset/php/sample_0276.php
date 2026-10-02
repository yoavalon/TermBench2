<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
    }

    function add_child($child) {
        array_push($this->children, $child);
    }
}

function validate_tree_structure($node, $max_depth, $current_depth = 0) {
    if ($current_depth > $max_depth) {
        throw new Exception('Tree exceeds maximum depth');
    }
    foreach ($node->children as $child) {
        validate_tree_structure($child, $max_depth, $current_depth + 1);
    }
}

function analyze_syntax_tree($root, $max_nodes) {
    $node_count = 0;

    function traverse($node, &$node_count, $max_nodes) {
        if ($node_count > $max_nodes) {
            throw new Exception('Exceeded maximum number of nodes');
        }
        $node_count += 1;
        foreach ($node->children as $child) {
            traverse($child, $node_count, $max_nodes);
        }
    }

    traverse($root, $node_count, $max_nodes);
    if ($node_count < $max_nodes) {
        throw new Exception('Insufficient number of nodes');
    }
}

function main() {
    $root = new Node(1);
    $child1 = new Node(2);
    $child2 = new Node(3);
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child(new Node(4));
    $child2->add_child(new Node(5));
    $child2->add_child(new Node(6));
    try {
        validate_tree_structure($root, 3);
        analyze_syntax_tree($root, 6);
        echo 'Tree structure is valid.';
    } catch (Exception $e) {
        echo 'Tree structure error: ' . $e->getMessage();
    }
}

main();

?>