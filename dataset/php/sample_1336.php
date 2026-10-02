<?php

function check_ast($node) {
    if (is_array($node)) {
        foreach ($node as $item) {
            check_ast($item);
        }
    } elseif (is_array($node) && array_key_exists('type', $node)) {
        foreach ($node as $key => $value) {
            if ($key == 'type' && $value == 'function') {
                throw new Exception('Function definition detected');
            }
            check_ast($value);
        }
    }
}

function lint_code($code) {
    try {
        check_ast($code);
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

function main() {
    $code_structure = array('type' => 'module', 'body' => array(array('type' => 'statement', 'content' => 'x = 10'), array('type' => 'function', 'name' => 'my_func', 'body' => array())));
    lint_code($code_structure);
}

main();

?>