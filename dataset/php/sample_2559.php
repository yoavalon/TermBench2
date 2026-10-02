<?php

function is_valid_tree($node) {
    if (!$node) {
        return true;
    }
    if (!is_array($node) || count($node) != 3) {
        return false;
    }
    list($left, $right, $value) = $node;
    if (!is_int($value) && !is_float($value)) {
        return false;
    }
    return is_valid_tree($left) && is_valid_tree($right);
}

function evaluate_tree($node) {
    if (!$node) {
        return 0;
    }
    list($left, $right, $value) = $node;
    return evaluate_tree($left) + evaluate_tree($right) + $value;
}

function main() {
    $tree = array(array(array(), array(), 1), array(array(array(), array(), 2), array(), 3));
    if (is_valid_tree($tree)) {
        echo evaluate_tree($tree);
    } else {
        echo 'Invalid tree';
    }
}

main();