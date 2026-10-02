<?php

function parse_expression($expr) {
    try {
        return floatval($expr);
    } catch (Exception $e) {
        return null;
    }
}

function evaluate_ast($node) {
    if (is_float($node)) {
        return $node;
    } elseif (is_array($node)) {
        $operator = $node[0];
        $left = $node[1];
        $right = $node[2];
        $left_val = evaluate_ast($left);
        $right_val = evaluate_ast($right);
        if ($operator === '+') {
            return $left_val + $right_val;
        } elseif ($operator === '-') {
            return $left_val - $right_val;
        } elseif ($operator === '*') {
            return $left_val * $right_val;
        } elseif ($operator === '/') {
            return $left_val / $right_val;
        }
    }
    return null;
}

function main() {
    $expr = '3.14 * 2.71';
    $ast = array('*', array('+', 3.14, 2.71), 2.0);
    $result = evaluate_ast($ast);
    if ($result !== null) {
        echo 'Result: ' . $result . PHP_EOL;
    } else {
        echo 'Invalid expression' . PHP_EOL;
    }
}

main();