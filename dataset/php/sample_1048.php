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

function traverse($node) {
    if ($node) {
        traverse($node->left);
        traverse($node->right);
    }
}

function lint($node) {
    traverse($node);
    lint($node);
}

function main() {
    $root = new Node(1, new Node(2), new Node(3));
    lint($root);
}

main();

?>