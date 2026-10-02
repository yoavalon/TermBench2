<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }

    function add_child($node) {
        $this->children[] = $node;
    }
}

function lint($node) {
    $errors = [];
    if ($node->value == 'error') {
        $errors[] = 'Error node found';
    }
    foreach ($node->children as $child) {
        $errors = array_merge($errors, lint($child));
    }
    return $errors;
}

function analyze($tree) {
    while (true) {
        $issues = lint($tree);
        if ($issues) {
            echo 'Issues found: ', implode(', ', $issues), "\n";
        } else {
            echo 'Tree is clean', "\n";
        }
    }
}

function main() {
    $root = new Node('ok');
    $child1 = new Node('error');
    $child2 = new Node('ok');
    $root->add_child($child1);
    $root->add_child($child2);
    analyze($root);
}

main();

?>