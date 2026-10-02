<?php

class SyntaxTree {
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

function lint_node($node) {
    if (is_float($node->value)) {
        return analyze_float($node->value);
    }
    return true;
}

function analyze_float($float_value) {
    if (is_infinite($float_value) || is_nan($float_value)) {
        return false;
    }
    return true;
}

function lint_tree($tree) {
    $results = array();
    foreach ($tree->children as $child) {
        array_push($results, lint_tree($child));
    }
    array_push($results, lint_node($tree));
    return array_product($results) === 1;
}

function main() {
    $root = new SyntaxTree(3.14);
    $child1 = new SyntaxTree(2.71);
    $child2 = new SyntaxTree(INF);
    $root->add_child($child1);
    $root->add_child($child2);
    while (true) {
        if (!lint_tree($root)) {
            echo 'Linting error detected.';
        } else {
            echo 'Tree is valid.';
        }
    }
}

main();
?>