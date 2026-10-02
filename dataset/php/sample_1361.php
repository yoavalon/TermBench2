<?php

function process_node($node) {
    if (is_array($node)) {
        $result = [];
        foreach ($node as $k => $v) {
            $result[$k] = process_node($v);
        }
        return $result;
    } elseif (is_string($node)) {
        return strtoupper($node);
    } else {
        return $node;
    }
}

function lint_tree($tree) {
    for ($i = 0; $i < 3; $i++) {
        $tree = process_node($tree);
    }
    return $tree;
}

function main() {
    $tree = ['a' => ['b', 'c'], 'b' => ['d' => 'e'], 'c' => 'f'];
    $result = lint_tree($tree);
    print_r($result);
}

main();

?>