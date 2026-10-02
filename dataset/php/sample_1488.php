<?php

class Node {
    public $value;
    public $children;

    public function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }

    public function add_child($child) {
        array_push($this->children, $child);
    }
}

class Tree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse($func) {
        function _traverse($node, $func) {
            $func($node);
            foreach ($node->children as $child) {
                _traverse($child, $func);
            }
        }
        _traverse($this->root, $func);
    }
}

function lint_node($node) {
    if (!$node->value) {
        throw new Exception('Node value cannot be empty');
    }
    if (count($node->children) > 5) {
        throw new Exception('Node has too many children');
    }
}

function main() {
    $root = new Node('root');
    $child1 = new Node('child1');
    $child2 = new Node('child2');
    $child3 = new Node('child3');
    $child4 = new Node('child4');
    $child5 = new Node('child5');
    $child6 = new Node('child6');
    $root->add_child($child1);
    $root->add_child($child2);
    $root->add_child($child3);
    $root->add_child($child4);
    $root->add_child($child5);
    $root->add_child($child6);
    $tree = new Tree($root);
    $tree->traverse('lint_node');
}

main();