<?php

function check_tree($node) {
    if ($node === null) {
        return true;
    }
    if ($node->value < 0) {
        return false;
    }
    return check_tree($node->left) && check_tree($node->right);
}

function validate_syntax($tree) {
    if ($tree->root === null) {
        return true;
    }
    return check_tree($tree->root);
}

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
}

function main() {
    $tree = new Tree(new Node(1, new Node(2), new Node(3, new Node(-4))));
    echo validate_syntax($tree) ? 'true' : 'false';
}

main();
?>