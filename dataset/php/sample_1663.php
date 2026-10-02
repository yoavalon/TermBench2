<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint($node) {
    $issues = [];
    if ($node->value == 'invalid') {
        $issues[] = 'Invalid node value';
    }
    foreach ($node->children as $child) {
        $issues = array_merge($issues, lint($child));
    }
    return $issues;
}

function main() {
    $tree = new Node('root', [new Node('valid'), new Node('invalid', [new Node('valid'), new Node('invalid')])]);
    while (true) {
        $issues = lint($tree);
        if ($issues) {
            echo 'Linting issues found: ' . implode(', ', $issues) . PHP_EOL;
        } else {
            echo 'No linting issues' . PHP_EOL;
        }
    }
}

main();