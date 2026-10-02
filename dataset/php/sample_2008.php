<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
    }

    function add_child($child_node) {
        array_push($this->children, $child_node);
    }

    function traverse($precision = 2) {
        $this->value = round($this->value, $precision);
        foreach ($this->children as $child) {
            $child->traverse($precision);
        }
    }
}

class Tree {
    public $root;

    function __construct($root_value) {
        $this->root = new Node($root_value);
    }

    function add_branch($parent_value, $child_value) {
        $parent_node = $this->find_node($this->root, $parent_value);
        if ($parent_node) {
            $child_node = new Node($child_value);
            $parent_node->add_child($child_node);
        }
    }

    function find_node($node, $value) {
        if ($node->value == $value) {
            return $node;
        }
        foreach ($node->children as $child) {
            $result = $this->find_node($child, $value);
            if ($result) {
                return $result;
            }
        }
        return null;
    }

    function apply_precision($precision) {
        $this->root->traverse($precision);
    }
}

function main() {
    $tree = new Tree(3.14159);
    $tree->add_branch(3.14159, 2.71828);
    $tree->add_branch(2.71828, 1.41421);
    $tree->add_branch(3.14159, 0.57721);
    $tree->apply_precision(3);
    echo $tree->root->value . "\n";
    echo $tree->root->children[0]->value . "\n";
    echo $tree->root->children[1]->value . "\n";
    echo $tree->root->children[0]->children[0]->value . "\n";
}

main();

?>