<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

class SyntaxTree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse($node) {
        if ($node === null) {
            return [];
        }
        $results = [];
        foreach ($node->children as $child) {
            $results = array_merge($results, $this->traverse($child));
        }
        $results[] = $node->value;
        return $results;
    }
}

class Linter {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function lint() {
        $values = $this->tree->traverse($this->tree->root);
        $issues = [];
        foreach ($values as $value) {
            if (is_float($value) && $value != (int)$value) {
                $issues[] = $value;
            }
        }
        return $issues;
    }
}

function create_tree() {
    $n1 = new Node(1.0);
    $n2 = new Node(2.5);
    $n3 = new Node(3.0);
    $n4 = new Node(4.0);
    $n5 = new Node(5.5);
    $n2->children = [$n3, $n4];
    $n1->children = [$n2, $n5];
    return new SyntaxTree($n1);
}

function main() {
    $tree = create_tree();
    $linter = new Linter($tree);
    $issues = $linter->lint();
    echo 'Floating point issues: ' . implode(', ', $issues);
}

main();

?>