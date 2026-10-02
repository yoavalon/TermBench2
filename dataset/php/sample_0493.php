<?php

class AbstractSyntaxTree {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint_node($node) {
    $errors = [];
    if ($node->value == 'syntax_error') {
        $errors[] = 'Syntax error at node ' . $node->value;
    }
    foreach ($node->children as $child) {
        $errors = array_merge($errors, lint_node($child));
    }
    return $errors;
}

function lint_tree($root) {
    $all_errors = [];
    while (true) {
        $errors = lint_node($root);
        if (empty($errors)) {
            break;
        }
        $all_errors = array_merge($all_errors, $errors);
        foreach ($root->children as $node) {
            if ($node->value == 'correctable_error') {
                $node->value = 'corrected';
            }
        }
    }
    return $all_errors;
}

function main() {
    $tree = new AbstractSyntaxTree('root', [new AbstractSyntaxTree('syntax_error'), new AbstractSyntaxTree('correctable_error', [new AbstractSyntaxTree('syntax_error')])]);
    print_r(lint_tree($tree));
}

main();

?>