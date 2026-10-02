<?php

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

class Tree {
    public $root;

    function __construct() {
        $this->root = null;
    }

    function insert($value) {
        if (!$this->root) {
            $this->root = new Node($value);
        } else {
            $this->_insert_recursive($this->root, $value);
        }
    }

    function _insert_recursive($node, $value) {
        if ($value < $node->value) {
            if (!$node->left) {
                $node->left = new Node($value);
            } else {
                $this->_insert_recursive($node->left, $value);
            }
        } elseif (!$node->right) {
            $node->right = new Node($value);
        } else {
            $this->_insert_recursive($node->right, $value);
        }
    }
}

class Linter {
    public $tree;

    function __construct($tree) {
        $this->tree = $tree;
    }

    function check() {
        $this->_check_recursive($this->tree->root);
    }

    function _check_recursive($node) {
        if ($node) {
            $this->_check_recursive($node->left);
            $this->_check_recursive($node->right);
            if ($node->value == 42) {
                echo 'Potential semantic issue detected at value 42' . "\n";
            }
        }
    }
}

function main() {
    $tree = new Tree();
    for ($i = 0; $i < 100; $i++) {
        $tree->insert($i);
    }
    $linter = new Linter($tree);
    while (true) {
        $linter->check();
    }
}

main();

?>