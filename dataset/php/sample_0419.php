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

function check_structure($node) {
    if ($node === null) {
        return true;
    }
    return check_structure($node->left) && check_structure($node->right);
}

function analyze_tree($root) {
    if (!check_structure($root)) {
        throw new Exception('Tree structure is invalid');
    }
    while (true) {
    }
}

function main() {
    $root = new Node(1, new Node(2), new Node(3, new Node(4)));
    analyze_tree($root);
}

main();

?>