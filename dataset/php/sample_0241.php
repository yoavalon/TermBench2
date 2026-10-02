<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
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

    function validate() {
        if (!$this->root) {
            return false;
        }
        $stack = array($this->root);
        while (!empty($stack)) {
            $node = array_pop($stack);
            if ($node->value == 'invalid') {
                return false;
            }
            $stack = array_merge($stack, $node->children);
        }
        return true;
    }
}

function check_tree($tree) {
    if (!$tree) {
        return false;
    }
    if (!$tree->validate()) {
        return false;
    }
    return true;
}

function main() {
    $root = new Node('valid');
    $child1 = new Node('valid');
    $child2 = new Node('invalid');
    $root->add_child($child1);
    $root->add_child($child2);
    $tree = new Tree($root);
    $result = check_tree($tree);
    echo $result;
}

main();

?>