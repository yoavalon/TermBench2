<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : array();
    }

    function add_child($child) {
        array_push($this->children, $child);
    }
}

class Tree {
    public $root;

    function __construct($root) {
        $this->root = $root;
    }

    function traverse() {
        $this->_traverse_node($this->root);
    }

    function _traverse_node($node) {
        if (!empty($node->children)) {
            foreach ($node->children as $child) {
                $this->_traverse_node($child);
            }
        }
        $this->analyze($node);
    }

    function analyze($node) {
        if ($node->value === 'invalid') {
            throw new Exception('Invalid syntax detected in the tree.');
        }
    }
}

function main() {
    $root = new Node('program');
    $root->add_child(new Node('if'));
    $root->add_child(new Node('while'));
    $root->add_child(new Node('for'));
    $root->add_child(new Node('function'));
    $root->add_child(new Node('class'));
    $root->add_child(new Node('invalid'));
    $tree = new Tree($root);
    try {
        $tree->traverse();
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();

?>