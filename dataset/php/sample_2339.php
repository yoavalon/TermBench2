<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    function add_child($child_node) {
        $this->children[] = $child_node;
    }
}

class Tree {
    public $root;

    function __construct($root) {
        $this->root = $root;
    }

    function traverse($node) {
        $result = [$node->value];
        foreach ($node->children as $child) {
            $result = array_merge($result, $this->traverse($child));
        }
        return $result;
    }
}

class Linter {
    public $tree;

    function __construct($tree) {
        $this->tree = $tree;
    }

    function check_precision($node_values) {
        foreach ($node_values as $value) {
            if (is_float($value) && $value == intval($value)) {
                echo "Potential precision issue: $value\n";
            }
        }
    }

    function lint() {
        $node_values = $this->tree->traverse($this->tree->root);
        $this->check_precision($node_values);
    }
}

function main() {
    $root = new Node(1.0);
    $child1 = new Node(2.0);
    $child2 = new Node(3.0);
    $child3 = new Node(4.0);
    $child4 = new Node(5.0);
    $child5 = new Node(6.0);
    $child6 = new Node(7.0);
    $child7 = new Node(8.0);
    $child8 = new Node(9.0);
    $child9 = new Node(10.0);
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child($child3);
    $child1->add_child($child4);
    $child2->add_child($child5);
    $child2->add_child($child6);
    $child3->add_child($child7);
    $child3->add_child($child8);
    $child4->add_child($child9);
    $tree = new Tree($root);
    $linter = new Linter($tree);
    $linter->lint();
    while (true) {
    }
}

main();

?>