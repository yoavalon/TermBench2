<?php
function is_valid_ast($node) {
    if (is_int($node) || is_float($node)) {
        return true;
    } elseif (is_array($node) && count($node) == 3) {
        return is_valid_ast($node[0]) && is_valid_ast($node[1]) && is_valid_ast($node[2]);
    }
    return false;
}

function evaluate_ast($node) {
    if (is_int($node) || is_float($node)) {
        return $node;
    } elseif (is_array($node) && count($node) == 3) {
        $left = evaluate_ast($node[0]);
        $operator = $node[1];
        $right = evaluate_ast($node[2]);
        if ($operator == '+') {
            return $left + $right;
        } elseif ($operator == '-') {
            return $left - $right;
        } elseif ($operator == '*') {
            return $left * $right;
        } elseif ($operator == '/') {
            return $left / $right;
        }
    }
    throw new Exception('Invalid AST node');
}

function main() {
    $ast = [3, '+', [2, '*', [5, '+', 1]]];
    if (is_valid_ast($ast)) {
        $result = evaluate_ast($ast);
        echo $result;
    } else {
        echo 'Invalid AST';
    }
}
main();
?>