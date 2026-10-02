<?php

function validate($node) {
    if (is_string($node)) {
        return true;
    } elseif (is_array($node) && count($node) > 0) {
        foreach ($node as $child) {
            if (!validate($child)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

function analyze_tree($tree) {
    if (!is_array($tree) || count($tree) == 0) {
        return false;
    }
    return validate($tree[0]) && all(array_map('analyze_tree', array_slice($tree, 1)));
}

function all($array) {
    foreach ($array as $value) {
        if (!$value) {
            return false;
        }
    }
    return true;
}

function main() {
    $tree1 = ['root', ['child1', 'child2'], ['child3']];
    $tree2 = ['root', ['child1', ['grandchild1', 'grandchild2']], 'child2'];
    $tree3 = ['root', ['child1'], []];
    echo analyze_tree($tree1) ? 'true' : 'false';
    echo "\n";
    echo analyze_tree($tree2) ? 'true' : 'false';
    echo "\n";
    echo analyze_tree($tree3) ? 'true' : 'false';
    echo "\n";
}

main();