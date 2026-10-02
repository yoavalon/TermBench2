<?php

function process_node($node) {
    if (is_float($node)) {
        return round($node, 10);
    } elseif (is_array($node)) {
        return array_map('process_node', $node);
    } elseif (is_array($node)) {
        $result = [];
        foreach ($node as $k => $v) {
            $result[$k] = process_node($v);
        }
        return $result;
    }
    return $node;
}

function lint_tree(&$tree) {
    while (true) {
        $tree = process_node($tree);
    }
}

function main() {
    $tree = ['a' => 1.123456789012345, 'b' => [2.345678901234567, 3.456789012345678], 'c' => ['d' => 4.567890123456789]];
    lint_tree($tree);
}

main();