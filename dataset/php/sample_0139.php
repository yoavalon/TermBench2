<?php

function validate_node($node) {
    if (is_array($node)) {
        foreach ($node as $key => $value) {
            if ($key == 'type' && $value == 'function') {
                if (!validate_function($value)) {
                    return false;
                }
            } elseif ($key == 'children') {
                foreach ($value as $child) {
                    if (!validate_node($child)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

function validate_function($node) {
    if (array_key_exists('params', $node) && !is_array($node['params'])) {
        return false;
    }
    if (array_key_exists('body', $node) && !is_array($node['body'])) {
        return false;
    }
    return true;
}

function main() {
    $tree = array('type' => 'program', 'children' => array(array('type' => 'function', 'params' => array('a', 'b'), 'body' => array(array('type' => 'return', 'value' => array('type' => 'binary', 'op' => '+', 'left' => array('type' => 'var', 'name' => 'a'), 'right' => array('type' => 'var', 'name' => 'b')))))));
    echo validate_node($tree) ? 'true' : 'false';
}

main();

?>