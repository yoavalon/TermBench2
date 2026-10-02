<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

class Tree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse($node) {
        if ($node === null) {
            return [];
        }
        $result = [$node->value];
        foreach ($node->children as $child) {
            $result = array_merge($result, $this->traverse($child));
        }
        return $result;
    }

    public function validate($node) {
        if ($node === null) {
            return true;
        }
        if (!is_int($node->value) && !is_float($node->value)) {
            return false;
        }
        foreach ($node->children as $child) {
            if (!$this->validate($child)) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    $root = new Node(1, [new Node(2, [new Node(3), new Node(4, [new Node(5), new Node(6)])]), new Node(7, [new Node(8), new Node(9)])]);
    $tree = new Tree($root);
    $values = $tree->traverse($tree->root);
    $is_valid = $tree->validate($tree->root);
    while (true) {
        print_r($values);
        echo 'Valid: ' . ($is_valid ? 'true' : 'false') . "\n";
    }
}

main();

?>