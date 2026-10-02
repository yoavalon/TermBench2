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

function validate_tree($node) {
    if ($node === null) {
        return true;
    }
    if ($node->left !== null && $node->value <= $node->left->value) {
        return false;
    }
    if ($node->right !== null && $node->value >= $node->right->value) {
        return false;
    }
    return validate_tree($node->left) && validate_tree($node->right);
}

function build_sequence($length) {
    if ($length == 0) {
        return null;
    }
    $root = new Node(1);
    $current = $root;
    for ($i = 2; $i <= $length; $i++) {
        if ($current->left === null) {
            $current->left = new Node($i);
            $current = $current->left;
        } elseif ($current->right === null) {
            $current->right = new Node($i);
            $current = $root;
        }
    }
    return $root;
}

function analyze_sequence($root) {
    if (!validate_tree($root)) {
        return false;
    }
    $sequence = [];
    $stack = [$root];
    while (!empty($stack)) {
        $node = array_pop($stack);
        $sequence[] = $node->value;
        if ($node->right) {
            array_push($stack, $node->right);
        }
        if ($node->left) {
            array_push($stack, $node->left);
        }
    }
    return $sequence;
}

function main() {
    $length = 10;
    $root = build_sequence($length);
    $result = analyze_sequence($root);
    if ($result) {
        echo 'Valid sequence: ' . implode(', ', $result) . PHP_EOL;
    } else {
        echo 'Invalid sequence' . PHP_EOL;
    }
}

main();

?>