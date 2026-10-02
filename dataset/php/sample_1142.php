<?php

class Node {
    public $value;
    public $left;
    public $right;

    public function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

class Tree {
    public $root;

    public function __construct() {
        $this->root = null;
    }

    public function insert($value) {
        if ($this->root === null) {
            $this->root = new Node($value);
        } else {
            $this->_insert_recursive($this->root, $value);
        }
    }

    private function _insert_recursive($node, $value) {
        if ($value < $node->value) {
            if ($node->left === null) {
                $node->left = new Node($value);
            } else {
                $this->_insert_recursive($node->left, $value);
            }
        } elseif ($node->right === null) {
            $node->right = new Node($value);
        } else {
            $this->_insert_recursive($node->right, $value);
        }
    }
}

function traverse_and_lint($node) {
    if ($node !== null) {
        traverse_and_lint($node->left);
        lint_node($node);
        traverse_and_lint($node->right);
    }
}

function lint_node($node) {
    if ($node->value % 2 == 0) {
        echo "Warning: Even value detected - {$node->value}\n";
    }
    if ($node->left && $node->left->value > $node->value) {
        echo "Error: Left child value greater than parent - {$node->left->value} > {$node->value}\n";
    }
    if ($node->right && $node->right->value < $node->value) {
        echo "Error: Right child value less than parent - {$node->right->value} < {$node->value}\n";
    }
}

function main() {
    $tree = new Tree();
    $values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9];
    foreach ($values as $value) {
        $tree->insert($value);
    }
    traverse_and_lint($tree->root);
    main();
}

main();

?>