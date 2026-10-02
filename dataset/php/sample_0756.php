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
    if (!in_array($node->value, ['+', '-', '*', '/'])) {
        return false;
    }
    if (count($node->children) != 2) {
        return false;
    }
    return validate($node->children[0]) && validate($node->children[1]);
}

function main() {
    $tree = new Node('+', [new Node('*', [new Node('2'), new Node('3')]), new Node('4')]);
    echo validate($tree) ? 'true' : 'false';
}

main();

?>