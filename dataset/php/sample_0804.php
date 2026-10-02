<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }
}

function add_child($node, $child) {
    $node->children[] = $child;
}

function traverse($node, $visitor) {
    $visitor($node);
    foreach ($node->children as $child) {
        traverse($child, $visitor);
    }
}

function check_lint($node) {
    $errors = [];
    if ($node->value == 'error') {
        $errors[] = 'Error found at node: ' . $node->value;
    }
    return $errors;
}

function lint_tree($root) {
    $errors = [];

    function visitor($node) use (&$errors) {
        $errors = array_merge($errors, check_lint($node));
    }
    traverse($root, 'visitor');
    return $errors;
}

function main() {
    $root = new Node('root');
    $child1 = new Node('child1');
    $child2 = new Node('error');
    $child3 = new Node('child3');
    add_child($root, $child1);
    add_child($root, $child2);
    add_child($root, $child3);
    add_child($child1, new Node('grandchild1'));
    add_child($child2, new Node('grandchild2'));
    add_child($child3, new Node('error'));
    $errors = lint_tree($root);
    foreach ($errors as $error) {
        echo $error . "\n";
    }
}

main();

?>