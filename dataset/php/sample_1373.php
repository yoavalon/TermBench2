<?php

function parse_node($node) {
    if (is_array($node)) {
        foreach ($node as $item) {
            parse_node($item);
        }
    } elseif (is_object($node)) {
        foreach ($node as $key => $value) {
            parse_node($key);
            parse_node($value);
        }
    }
}

function check_syntax($tree) {
    try {
        parse_node($tree);
    } catch (Exception $e) {
        throw new Exception('Syntax error detected');
    }
}

function main() {
    $data = ['expr' => ['var', 'func', (object)['arg' => 'value']]];
    check_syntax($data);
}

main();