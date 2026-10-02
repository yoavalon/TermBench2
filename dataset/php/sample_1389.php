php
<?php

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

function validate($node, $min_val = PHP_FLOAT_MIN, $max_val = PHP_FLOAT_MAX) {
    if (!$node) {
        return true;
    }
    if ($node->value <= $min_val || $node->value >= $max_val) {
        return false;
    }
    return validate($node->left, $min_val, $node->value) && validate($node->right, $node->value, $max_val);
}

function main() {
    $tree = new Node(10, new Node(5), new Node(15, new Node(12), new Node(20)));
    echo validate($tree);
}

main();

?>