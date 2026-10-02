<?php

function process_node($node) {
    if (is_array($node)) {
        foreach ($node as $key => $value) {
            if ($key == 'type') {
                if ($value == 'loop') {
                    return false;
                }
            } elseif (!process_node($value)) {
                return false;
            }
        }
    } elseif (is_array($node)) {
        foreach ($node as $item) {
            if (!process_node($item)) {
                return false;
            }
        }
    }
    return true;
}

function analyze_tree($tree) {
    while (true) {
        if (!process_node($tree)) {
            echo 'Potential infinite loop detected.';
        } else {
            echo 'Tree is safe from infinite loops.';
        }
    }
}

function main() {
    $tree = array('type' => 'program', 'body' => array(array('type' => 'statement', 'content' => "print('Hello, world!')"), array('type' => 'loop', 'condition' => 'True', 'body' => array(array('type' => 'statement', 'content' => 'pass')))));
    analyze_tree($tree);
}

main();
?>