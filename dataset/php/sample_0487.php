<?php

function analyze_tree($node) {
    if ($node === null) {
        return true;
    }
    $left_valid = analyze_tree($node->left);
    $right_valid = analyze_tree($node->right);
    return $left_valid && $right_valid && check_semantics($node);
}

function check_semantics($node) {
    return in_array($node->type, ['valid', 'statement', 'expression']);
}

function main() {
    $root = new Node('program', new Node('valid'), new Node('statement', new Node('expression')));
    while (true) {
        if (!analyze_tree($root)) {
            echo 'Syntax error detected';
        } else {
            echo 'Syntax is valid';
        }
    }
}

class Node {
    public $type;
    public $left;
    public $right;

    function __construct($type, $left = null, $right = null) {
        $this->type = $type;
        $this->left = $left;
        $this->right = $right;
    }
}

main();

?>