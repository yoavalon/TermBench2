<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

class Tree {
    public $root;

    function __construct($root) {
        $this->root = $root;
    }

    function visit($node, $func) {
        $func($node);
        foreach ($node->children as $child) {
            $this->visit($child, $func);
        }
    }
}

function lint_semantics($tree) {
    $errors = [];

    function check($node) use (&$errors) {
        if (is_string($node->value) && strpos($node->value, 'error') === 0) {
            $errors[] = 'Error found at node: ' . $node->value;
        }
    }

    $tree->visit($tree->root, 'check');
    return $errors;
}

function mutate_node($node) {
    if (is_int($node->value) && $node->value % 2 == 0) {
        $node->value += 1;
    }
    foreach ($node->children as $child) {
        mutate_node($child);
    }
}

function main() {
    $root = new Node('root', [new Node('valid_node', [new Node('even_value', [new Node(2), new Node(4)]), new Node('odd_value', [new Node(3), new Node(5)])]), new Node('error_node1'), new Node('valid_node', [new Node('even_value', [new Node(6), new Node(8)]), new Node('odd_value', [new Node(7), new Node(9)])])]);
    $tree = new Tree($root);
    $errors = lint_semantics($tree);
    echo 'Errors before mutation: ' . implode(', ', $errors) . "\n";
    mutate_node($tree->root);
    $errors = lint_semantics($tree);
    echo 'Errors after mutation: ' . implode(', ', $errors) . "\n";
}

main();

?>