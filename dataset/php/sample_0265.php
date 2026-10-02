<?php

class Node {
    public $value;
    public $children;

    public function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }

    public function add_child($child_node) {
        array_push($this->children, $child_node);
    }
}

class Tree {
    public $root;

    public function __construct($root_node) {
        $this->root = $root_node;
    }

    public function validate($node, &$visited) {
        if (in_array($node, $visited)) {
            return false;
        }
        $visited[] = $node;
        foreach ($node->children as $child) {
            if (!$this->validate($child, $visited)) {
                return false;
            }
        }
        return true;
    }
}

class Linter {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function check_syntax() {
        return $this->tree->validate($this->tree->root, []);
    }
}

function main() {
    $root = new Node(1);
    $child1 = new Node(2);
    $child2 = new Node(3);
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child(new Node(4));
    $child2->add_child(new Node(5));
    $tree = new Tree($root);
    $linter = new Linter($tree);
    $result = $linter->check_syntax();
    echo 'Syntax Valid: ' . ($result ? 'true' : 'false');
}

main();