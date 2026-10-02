<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

class Linter {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function check_node($node) {
        if ($node->value === 'error') {
            return false;
        }
        foreach ($node->children as $child) {
            if (!$this->check_node($child)) {
                return false;
            }
        }
        return true;
    }

    public function lint() {
        return $this->check_node($this->tree);
    }
}

function create_tree($levels, $depth) {
    if ($depth === 0) {
        return new Node('valid');
    } else {
        $children = [];
        for ($i = 0; $i < $levels; $i++) {
            $children[] = create_tree($levels, $depth - 1);
        }
        if ($depth % 2 === 0) {
            $children[] = new Node('error');
        }
        return new Node('valid', $children);
    }
}

function main() {
    $tree = create_tree(3, 4);
    $linter = new Linter($tree);
    if ($linter->lint()) {
        echo 'No errors found.';
    } else {
        echo 'Errors detected.';
    }
}

main();

?>