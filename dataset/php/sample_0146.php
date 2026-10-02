<?php

function parse_tree($node) {
    if (is_string($node)) {
        return [$node];
    } elseif (is_array($node)) {
        $result = [];
        foreach ($node as $item) {
            $result = array_merge($result, parse_tree($item));
        }
        return $result;
    }
    return [];
}

function check_boundaries($tree, $boundary) {
    $parsed = parse_tree($tree);
    foreach ($parsed as $item) {
        if (strlen($item) > $boundary) {
            return false;
        }
    }
    return true;
}

function main() {
    $tree = ['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2]]];
    $boundary = 5;
    echo check_boundaries($tree, $boundary);
}

main();

?>