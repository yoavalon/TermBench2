php
<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    public function add_child($node) {
        $this->children[] = $node;
    }
}

class Tree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse($node) {
        if (!empty($node->children)) {
            foreach ($node->children as $child) {
                $this->traverse($child);
            }
        }
    }

    public function validate() {
        $this->traverse($this->root);
        return true;
    }
}

class Validator {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function lint() {
        return $this->tree->validate();
    }
}

function main() {
    $root = new Node('start');
    $child1 = new Node('condition1');
    $child2 = new Node('condition2');
    $child3 = new Node('end');
    $root->add_child($child1);
    $root->add_child($child2);
    $child2->add_child($child3);
    $tree = new Tree($root);
    $validator = new Validator($tree);
    $result = $validator->lint();
    echo 'Validation result: ' . $result . PHP_EOL;
}

main();