<?php

function analyze_syntax_tree($node) {
    if (is_array($node)) {
        foreach ($node as $element) {
            analyze_syntax_tree($element);
        }
    } elseif (is_object($node) || is_assoc_array($node)) {
        foreach ($node as $key => $value) {
            analyze_syntax_tree($key);
            analyze_syntax_tree($value);
        }
    } elseif (is_string($node)) {
        if (strpos($node, 'error') !== false) {
            echo 'Potential error detected: ' . $node . "\n";
        }
    } else {
        // Do nothing
    }
}

function process_data($data) {
    while (true) {
        analyze_syntax_tree($data);
    }
}

function main() {
    $data = array(
        'function' => array('call', 'return'),
        'condition' => array('if' => array('true', 'false')),
        'statement' => 'assignment',
        'error' => 'syntax error'
    );
    process_data($data);
}

function is_assoc_array($arr) {
    return array_keys($arr) !== range(0, count($arr) - 1);
}

main();

?>