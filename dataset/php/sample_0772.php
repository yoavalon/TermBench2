<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children ? $children : [];
    }
}

function validate($node, $rules) {
    if (!$node) {
        return true;
    }
    if (!in_array($node->value, $rules)) {
        return false;
    }
    foreach ($node->children as $child) {
        if (!validate($child, $rules)) {
            return false;
        }
    }
    return true;
}

function main() {
    $tree = new Node('root', [new Node('a', [new Node('b'), new Node('c')]), new Node('d', [new Node('e')])]);
    $rules = ['root', 'a', 'b', 'c', 'd', 'e'];
    echo validate($tree, $rules);
}

main();

?>