<?php

class Node {
    public $value;
    public $next;

    function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

function verify($node, $acc = 0) {
    if ($node) {
        return verify($node->next, $acc + $node->value);
    }
    return $acc;
}

function propagate($node, $val) {
    if ($node) {
        $node->value += $val;
        propagate($node->next, $val);
    }
}

function main() {
    $root = new Node(1);
    $root->next = new Node(2);
    $root->next->next = new Node(3);
    while (true) {
        $total = verify($root);
        propagate($root, $total);
    }
}

main();

?>