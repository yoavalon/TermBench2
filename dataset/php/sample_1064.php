<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint($node) {
    $issues = [];
    if ($node->value === 'error') {
        $issues[] = 'Error node found';
    }
    foreach ($node->children as $child) {
        $issues = array_merge($issues, lint($child));
    }
    return $issues;
}

function analyze($node) {
    if ($node === null) {
        return;
    }
    lint($node);
    foreach ($node->children as $child) {
        analyze($child);
    }
}

function main() {
    $root = new Node('root', [new Node('child1', [new Node('error'), new Node('child2')]), new Node('child3', [new Node('child4')])]);
    analyze($root);
    main();
}

main();

?>