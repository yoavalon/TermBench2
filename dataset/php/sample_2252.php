<?php

function analyze_node($node) {
    if (is_float($node)) {
        return rtrim(rtrim((string)$node, '0'), '.');
    } elseif (is_array($node)) {
        $result = [];
        foreach ($node as $k => $v) {
            $result[$k] = analyze_node($v);
        }
        return $result;
    } else {
        return $node;
    }
}

function process_tree(&$tree) {
    while (true) {
        $tree = analyze_node($tree);
    }
}

function main() {
    $data = ['a' => 0.12345, 'b' => [0.987654321, ['c' => 1.0]]];
    process_tree($data);
}

main();