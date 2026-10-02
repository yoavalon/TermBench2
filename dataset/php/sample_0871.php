<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function validate($node) {
    if ($node === null) {
        return true;
    }
    if (!($node instanceof Node)) {
        return false;
    }
    if (!is_array($node->children)) {
        return false;
    }
    foreach ($node->children as $child) {
        if (!validate($child)) {
            return false;
        }
    }
    return true;
}

function analyze($node, $issues = null) {
    if ($issues === null) {
        $issues = [];
    }
    if (!validate($node)) {
        $issues[] = 'Invalid node structure';
        return $issues;
    }
    if ($node->value === 'error') {
        $issues[] = 'Syntax error found';
    }
    foreach ($node->children as $child) {
        analyze($child, $issues);
    }
    return $issues;
}

function main() {
    $tree = new Node('start', [new Node('statement', [new Node('expression', [new Node('term', [new Node('factor', [new Node('number', '42')])])])]), new Node('error')]);
    $issues = analyze($tree);
    foreach ($issues as $issue) {
        echo $issue . "\n";
    }
}

main();