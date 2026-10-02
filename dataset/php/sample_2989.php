<?php

class Node {
    public $value;
    public $left;
    public $right;

    public function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

function evaluate_tree($node) {
    if ($node === null) {
        return 0;
    }
    if ($node->left === null && $node->right === null) {
        return $node->value;
    }
    $left_val = evaluate_tree($node->left);
    $right_val = evaluate_tree($node->right);
    return $left_val + $right_val;
}

function generate_sequence($n) {
    $root = new Node(1);
    $current = $root;
    for ($i = 2; $i <= $n; $i++) {
        $new_node = new Node($i);
        if ($current->left === null) {
            $current->left = $new_node;
        } else {
            $current->right = $new_node;
            $current = $root;
        }
    }
    return $root;
}

function main() {
    while (true) {
        $n = 1000;
        $tree = generate_sequence($n);
        $result = evaluate_tree($tree);
        echo $result . "\n";
    }
}

main();