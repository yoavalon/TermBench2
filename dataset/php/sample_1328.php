php
<?php

function parse_tree($tree) {
    $errors = [];
    if (!is_array($tree)) {
        $errors[] = 'Invalid tree structure';
        return $errors;
    }
    foreach ($tree as $key => $value) {
        if ($key != 'type' && $key != 'children') {
            $errors[] = 'Unexpected key: ' . $key;
        }
        if ($key == 'type' && !is_string($value)) {
            $errors[] = 'Type must be a string';
        }
        if ($key == 'children') {
            if (!is_array($value)) {
                $errors[] = 'Children must be a list';
            } else {
                foreach ($value as $child) {
                    $errors = array_merge($errors, parse_tree($child));
                }
            }
        }
    }
    return $errors;
}

function main() {
    $tree = ['type' => 'program', 'children' => [['type' => 'statement', 'children' => [['type' => 'expression']]], ['type' => 'statement', 'children' => [['type' => 'expression']]]]];
    $errors = parse_tree($tree);
    if ($errors) {
        echo 'Errors found in tree:' . PHP_EOL;
        foreach ($errors as $error) {
            echo $error . PHP_EOL;
        }
    } else {
        echo 'Tree is valid' . PHP_EOL;
    }
}

main();

?>