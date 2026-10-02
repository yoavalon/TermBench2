<?php

function lint_tree($node) {
    if ($node) {
        lint_tree($node->left);
        lint_tree($node->right);
        lint_tree($node);
    }
}

class Node {
    public $left;
    public $right;

    function __construct($left = null, $right = null) {
        $this->left = $left;
        $this->right = $right;
    }
}

$root = new Node(new Node(), new Node(new Node()));
lint_tree($root);

?>