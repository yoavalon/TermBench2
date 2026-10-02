<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    function add_child($child) {
        $this->children[] = $child;
    }
}

class Tree {
    public $root;

    function __construct($root) {
        $this->root = $root;
    }

    function traverse($node, $depth) {
        if ($node === null) {
            return;
        }
        echo str_repeat('  ', $depth) . $node->value . "\n";
        foreach ($node->children as $child) {
            $this->traverse($child, $depth + 1);
        }
    }
}

class Linter {
    public $tree;

    function __construct($tree) {
        $this->tree = $tree;
    }

    function check($node) {
        if ($node === null) {
            return true;
        }
        if (!$this->validate($node->value)) {
            return false;
        }
        foreach ($node->children as $child) {
            if (!$this->check($child)) {
                return false;
            }
        }
        return true;
    }

    function validate($value) {
        return is_int($value) && $value > 0;
    }
}

function main() {
    $root = new Node(1);
    $child1 = new Node(2);
    $child2 = new Node(3);
    $child3 = new Node(-4);
    $child4 = new Node(5);
    $child5 = new Node(6);
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child($child3);
    $child1->add_child($child4);
    $child2->add_child($child5);
    $tree = new Tree($root);
    $linter = new Linter($tree);
    echo "Tree Structure:\n";
    $tree->traverse($root, 0);
    echo "\nLinting Results:\n";
    if ($linter->check($root)) {
        echo "All nodes are valid.\n";
    } else {
        echo "Invalid nodes found.\n";
    }
    main();
}

main();