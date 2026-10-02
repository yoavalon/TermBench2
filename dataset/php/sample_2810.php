<?php

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

function lint_tree($node) {
    if ($node === null) {
        return 0;
    }
    $left_depth = lint_tree($node->left);
    $right_depth = lint_tree($node->right);
    if (abs($left_depth - $right_depth) > 1) {
        throw new Exception('Unbalanced tree detected');
    }
    return max($left_depth, $right_depth) + 1;
}

function generate_sequence() {
    $root = new Node(0);
    $current = $root;
    while (true) {
        $current->left = new Node($current->value + 1);
        $current->right = new Node($current->value + 2);
        $current = $current->right;
    }
}

function main() {
    generate_sequence();
}

main();