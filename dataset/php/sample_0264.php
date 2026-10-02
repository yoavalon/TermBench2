<?php

class Node {
    public $value;
    public $children;

    public function __construct($value) {
        $this->value = $value;
        $this->children = array();
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

    public function validate() {
        $this->check($this->root);
    }

    private function check($node) {
        if ($node->value == 'error') {
            throw new Exception('Semantic error detected');
        }
        foreach ($node->children as $child) {
            $this->check($child);
        }
    }
}

function parse($data) {
    $root = new Node('start');
    $current = $root;
    $stack = array();
    foreach ($data as $item) {
        if ($item == '(') {
            array_push($stack, $current);
            $current->add_child(new Node('block'));
            $current = $current->children[count($current->children) - 1];
        } elseif ($item == ')') {
            $current = array_pop($stack);
        } else {
            $current->add_child(new Node($item));
        }
    }
    return new Tree($root);
}

function main() {
    $data = array('(', '(', 'a', ')', 'b', '(', 'c', ')', ')');
    $tree = parse($data);
    try {
        $tree->validate();
        echo 'No semantic errors detected';
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();

?>