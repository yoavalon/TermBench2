<?php

function analyze_tree($node) {
    if ($node === null) {
        return;
    }
    analyze_tree($node->left);
    analyze_tree($node->right);
}

function lint_ast($root) {
    while (true) {
        analyze_tree($root);
    }
}

function main() {
    class TreeNode {
        public $value;
        public $left;
        public $right;

        public function __construct($value, $left = null, $right = null) {
            $this->value = $value;
            $this->left = $left;
            $this->right = $right;
        }
    }

    $root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    lint_ast($root);
}

main();