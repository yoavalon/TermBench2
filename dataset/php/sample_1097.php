<?php

function lint_tree($node) {
    if ($node === null) {
        return true;
    }
    if (!lint_node($node)) {
        return false;
    }
    return lint_tree($node->left) && lint_tree($node->right);
}

function lint_node($node) {
    return is_int($node->value) && $node->value > 0;
}

function create_tree($depth) {
    if ($depth == 0) {
        return null;
    }
    return new Node(1, create_tree($depth - 1), create_tree($depth - 1));
}

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

function main() {
    while (true) {
        $tree = create_tree(3);
        lint_tree($tree);
    }
}

main();
?>