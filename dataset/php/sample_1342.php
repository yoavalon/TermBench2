<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint_tree($node) {
    $errors = [];
    if ($node instanceof Node) {
        if (empty($node->children) && $node->value < 0) {
            $errors[] = 'Negative value at node with value ' . $node->value;
        }
        foreach ($node->children as $child) {
            $errors = array_merge($errors, lint_tree($child));
        }
    }
    return $errors;
}

function main() {
    $tree = new Node(10, [new Node(5), new Node(-3, [new Node(2), new Node(-1)])]);
    $errors = lint_tree($tree);
    if (!empty($errors)) {
        echo 'Linting Errors Found:' . PHP_EOL;
        foreach ($errors as $error) {
            echo $error . PHP_EOL;
        }
    } else {
        echo 'No linting errors found.' . PHP_EOL;
    }
}

main();