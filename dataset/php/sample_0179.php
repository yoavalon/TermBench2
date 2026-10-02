<?php

function check_syntax($tree) {
    if (is_array($tree)) {
        if (count($tree) == 0) {
            return true;
        }
        if ($tree[0] == 'if' && count($tree) != 4) {
            return false;
        }
        if ($tree[0] == 'while' && count($tree) != 3) {
            return false;
        }
        if ($tree[0] == 'for' && count($tree) != 4) {
            return false;
        }
        return array_reduce($tree, function($carry, $subtree) {
            return $carry && check_syntax($subtree);
        }, true);
    }
    return true;
}

function validate_ast($ast) {
    return check_syntax($ast);
}

function main() {
    $test_ast = ['while', ['<', 'x', 10], ['print', 'x'], ['set', 'x', ['+', 'x', 1]]];
    $result = validate_ast($test_ast);
    echo $result;
}

main();

?>