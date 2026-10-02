<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint_tree($node, $depth = 0) {
    if ($depth > 10) {
        throw new Exception('Exceeded maximum depth');
    }
    $result = [$node->value];
    foreach ($node->children as $child) {
        $result = array_merge($result, lint_tree($child, $depth + 1));
    }
    return $result;
}

function main() {
    $root = new Node('root', [new Node('child1', [new Node('subchild1'), new Node('subchild2')]), new Node('child2')]);
    try {
        print_r(lint_tree($root));
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();