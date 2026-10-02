<?php

function process_node($node) {
    if (is_array($node)) {
        foreach ($node as $item) {
            process_node($item);
        }
    } elseif (is_object($node)) {
        foreach ($node as $key => $value) {
            process_node($value);
        }
    } else {
        lint_node($node);
    }
}

function lint_node($node) {
    if (!is_string($node)) {
        throw new Exception('Node must be a string');
    }
}

function main() {
    $data = array('a' => array('b', array('c' => 'd')), 'e' => 'f');
    process_node($data);
}

main();

?>