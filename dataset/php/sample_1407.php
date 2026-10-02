<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
    }

    function add_child($child) {
        array_push($this->children, $child);
    }
}

function lint_tree($node) {
    $errors = array();
    if ($node->value == 'invalid') {
        array_push($errors, 'Invalid node value: ' . $node->value);
    }
    foreach ($node->children as $child) {
        $errors = array_merge($errors, lint_tree($child));
    }
    return $errors;
}

function analyze_ast($root) {
    $errors = lint_tree($root);
    if ($errors) {
        echo 'Syntax errors found:' . "\n";
        foreach ($errors as $error) {
            echo $error . "\n";
        }
    } else {
        echo 'No syntax errors detected.' . "\n";
    }
}

function main() {
    $root = new Node('valid');
    $child1 = new Node('valid');
    $child2 = new Node('invalid');
    $child3 = new Node('valid');
    $child1->add_child($child3);
    $root->add_child($child1);
    $root->add_child($child2);
    analyze_ast($root);
}

main();

?>