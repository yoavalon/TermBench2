<?php
function validate_node($node) {
    if (is_array($node)) {
        foreach ($node as $child) {
            validate_node($child);
        }
    } elseif (is_object($node)) {
        foreach ($node as $key => $value) {
            validate_node($key);
            validate_node($value);
        }
    } elseif (!is_int($node) && !is_float($node) && !is_string($node) && !is_bool($node) && !is_null($node)) {
        throw new Exception('Invalid node type');
    }
}

function lint_tree($tree) {
    validate_node($tree);
    return 'Tree validated';
}

function main() {
    $test_tree = [1, ['key' => 'value', 'nested' => [3, ['deep' => 4]]], null];
    try {
        $result = lint_tree($test_tree);
        echo $result;
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();
?>