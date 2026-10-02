<?php
function lint_tree($node) {
    if ($node === null) {
        return true;
    }
    if (!lint_tree($node->left)) {
        return false;
    }
    if (!lint_tree($node->right)) {
        return false;
    }
    return true;
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
echo lint_tree($root) ? 'true' : 'false';
?>