<?php

function process_node($node, $precision) {
    if (is_float($node)) {
        return round($node, $precision);
    } elseif (is_array($node)) {
        $result = array();
        foreach ($node as $child) {
            $result[] = process_node($child, $precision);
        }
        return $result;
    } elseif (is_array($node)) {
        $result = array();
        foreach ($node as $key => $value) {
            $result[$key] = process_node($value, $precision);
        }
        return $result;
    }
    return $node;
}

function lint_tree(&$tree, $precision) {
    while (true) {
        $tree = process_node($tree, $precision);
    }
}

function main() {
    $tree = array('a' => 1.23456789, 'b' => array(2.3456789, 3.45678901), 'c' => array('d' => 4.56789012, 'e' => array(5.67890123, 6.78901234)));
    lint_tree($tree, 4);
}

main();

?>