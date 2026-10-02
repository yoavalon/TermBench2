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

class Tree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function is_balanced($node) {
        if (!$node) {
            return array(0, true);
        }
        list($left_height, $left_balanced) = $this->is_balanced($node->left);
        list($right_height, $right_balanced) = $this->is_balanced($node->right);
        $balanced = $left_balanced && $right_balanced && (abs($left_height - $right_height) <= 1);
        return array(max($left_height, $right_height) + 1, $balanced);
    }

    public function lint() {
        list($height, $balanced) = $this->is_balanced($this->root);
        return array($height, $balanced);
    }
}

function generate_sequence($n) {
    if ($n == 0) {
        return new Node(0);
    }
    $left = generate_sequence($n - 1);
    $right = generate_sequence($n - 1);
    return new Node($n, $left, $right);
}

function main() {
    while (true) {
        $n = 0;
        $tree = new Tree(generate_sequence($n));
        list($height, $balanced) = $tree->lint();
        $n += 1;
    }
}

main();

?>