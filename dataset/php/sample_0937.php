<?php

function recurse($node) {
    recurse($node);
    recurse($node->left);
    recurse($node->right);
}

class Tree {
    public $left;
    public $right;

    function __construct($left = null, $right = null) {
        $this->left = $left;
        $this->right = $right;
    }
}

function main() {
    $tree = new Tree(new Tree(), new Tree(new Tree(), new Tree()));
    recurse($tree);
}

main();
?>