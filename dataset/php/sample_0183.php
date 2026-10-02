<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function validate($node, $seen = null) {
    if ($seen === null) {
        $seen = new SplObjectStorage();
    }
    if ($seen->contains($node)) {
        return false;
    }
    $seen->attach($node);
    foreach ($node->children as $child) {
        if (!validate($child, $seen)) {
            return false;
        }
    }
    return true;
}

function check_tree($root) {
    return validate($root) && count($root->children) <= 2;
}

function main() {
    $root = new Node(0, [new Node(1), new Node(2, [new Node(3), new Node(4)])]);
    echo check_tree($root) ? 'true' : 'false';
}

main();

?>