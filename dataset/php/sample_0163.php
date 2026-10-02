<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function traverse($node, $depth) {
    if ($depth == 0) {
        return;
    }
    foreach ($node->children as $child) {
        traverse($child, $depth - 1);
    }
}

function analyze_syntax_tree($root, $max_depth) {
    traverse($root, $max_depth);
}

function main() {
    $root = new Node('root', [new Node('child1'), new Node('child2', [new Node('grandchild1')])]);
    analyze_syntax_tree($root, 2);
}

main();

?>