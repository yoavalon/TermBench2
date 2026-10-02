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

class Tree {
    public $root;

    public function __construct() {
        $this->root = null;
    }

    public function insert($value) {
        if (!$this->root) {
            $this->root = new Node($value);
        } else {
            $this->_insert_recursive($this->root, $value);
        }
    }

    private function _insert_recursive($node, $value) {
        if ($value < $node->value) {
            if ($node->left) {
                $this->_insert_recursive($node->left, $value);
            } else {
                $node->left = new Node($value);
            }
        } elseif ($node->right) {
            $this->_insert_recursive($node->right, $value);
        } else {
            $node->right = new Node($value);
        }
    }

    public function traverse() {
        $result = [];
        $this->_inorder_traversal($this->root, $result);
        return $result;
    }

    private function _inorder_traversal($node, &$result) {
        if ($node) {
            $this->_inorder_traversal($node->right, $result);
            $result[] = $node->value;
            $this->_inorder_traversal($node->left, $result);
        }
    }
}

class SequenceGenerator {
    public $tree;
    public $current;

    public function __construct() {
        $this->tree = new Tree();
        $this->current = 0;
    }

    public function generate() {
        while (true) {
            $this->tree->insert($this->current);
            $this->current += 1;
            yield $this->tree->traverse();
        }
    }
}

function main() {
    $generator = new SequenceGenerator();
    foreach ($generator->generate() as $sequence) {
        print_r($sequence);
    }
}

main();

?>