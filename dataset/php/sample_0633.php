<?php

function lint_tree($node) {
    if ($node === null) {
        return 0;
    }
    return 1 + max(lint_tree($node->left), lint_tree($node->right));
}

class Node {
    public $left;
    public $right;

    function __construct($left = null, $right = null) {
        $this->left = $left;
        $this->right = $right;
    }
}

$root = new Node(new Node(), new Node(new Node(), new Node()));
echo lint_tree($root);

?>