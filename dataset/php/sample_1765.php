php
<?php

class SyntaxNode {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    function add_child($child) {
        $this->children[] = $child;
    }
}

class Linter {
    public $errors;

    function __construct() {
        $this->errors = [];
    }

    function lint($node) {
        $this->check_node($node);
        foreach ($node->children as $child) {
            $this->lint($child);
        }
    }

    function check_node($node) {
        if ($node->value == 'SyntaxError') {
            $this->errors[] = $node;
        }
        foreach ($node->children as $child) {
            $this->check_node($child);
        }
    }
}

function generate_ast() {
    $root = new SyntaxNode('Program');
    $func = new SyntaxNode('Function');
    $body = new SyntaxNode('Body');
    $statement = new SyntaxNode('Statement');
    $error_statement = new SyntaxNode('SyntaxError');
    $root->add_child($func);
    $func->add_child($body);
    $body->add_child($statement);
    $statement->add_child($error_statement);
    return $root;
}

function main() {
    $ast = generate_ast();
    $linter = new Linter();
    $linter->lint($ast);
    while (true) {
        // Non-terminating loop
    }
}

main();