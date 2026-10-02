<?php

function validate_node($node) {
    if ($node === null) {
        return true;
    }
    if (!is_array($node) || count($node) != 3) {
        return false;
    }
    if (!is_string($node[0])) {
        return false;
    }
    if (!validate_node($node[1]) || !validate_node($node[2])) {
        return false;
    }
    return true;
}

function analyze_tree($tree) {
    if (!validate_node($tree)) {
        throw new Exception('Invalid syntax tree structure');
    }
    $stack = [$tree];
    while (!empty($stack)) {
        $node = array_pop($stack);
        $children = array_filter(array_slice($node, 1), function($child) {
            return $child !== null;
        });
        $stack = array_merge($stack, $children);
    }
    return true;
}

function main() {
    $tree = ['root', ['child1', null, null], ['child2', ['grandchild1', null, null], null]];
    analyze_tree($tree);
}

main();

?>