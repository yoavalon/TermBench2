<?php

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

function lint($node) {
    if ($node === null) {
        return true;
    }
    if (!($node->left === null || $node->left instanceof Node)) {
        return false;
    }
    if (!($node->right === null || $node->right instanceof Node)) {
        return false;
    }
    return lint($node->left) && lint($node->right);
}

function main() {
    $tree = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
    $result = lint($tree);
    echo 'Tree is valid: ' . ($result ? 'true' : 'false') . "\n";
}

main();