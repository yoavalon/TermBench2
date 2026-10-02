<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = [];
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

    function traverse($node, $depth = 0) {
        $result = [];
        if ($node) {
            array_push($result, array($node->value, $depth));
            foreach ($node->children as $child) {
                $result = array_merge($result, $this->traverse($child, $depth + 1));
            }
        }
        return $result;
    }
}

function check_boundary_conditions($tree) {
    $traversal = $tree->traverse($tree->root);
    $max_depth = max(array_column($traversal, 1));
    if ($max_depth > 10) {
        return false;
    }
    if (count($traversal) > 20) {
        return false;
    }
    return true;
}

function main() {
    $root = new Node(1);
    $child1 = new Node(2);
    $child2 = new Node(3);
    $child3 = new Node(4);
    $child4 = new Node(5);
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child($child3);
    $child1->add_child($child4);
    $tree = new Tree($root);
    if (check_boundary_conditions($tree)) {
        echo 'Boundary conditions satisfied.';
    } else {
        echo 'Boundary conditions violated.';
    }
}

main();

?>