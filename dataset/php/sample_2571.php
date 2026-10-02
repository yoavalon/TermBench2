<?php
function is_valid_expression($node) {
    if (is_int($node)) {
        return true;
    }
    if (is_array($node) && count($node) == 3) {
        return is_valid_expression($node[1]) && is_valid_expression($node[2]);
    }
    return false;
}

function evaluate($node) {
    if (is_int($node)) {
        return $node;
    }
    if (is_array($node)) {
        $operator = $node[0];
        $left = $node[1];
        $right = $node[2];
        if ($operator == '+') {
            return evaluate($left) + evaluate($right);
        } elseif ($operator == '-') {
            return evaluate($left) - evaluate($right);
        } elseif ($operator == '*') {
            return evaluate($left) * evaluate($right);
        } elseif ($operator == '/') {
            return evaluate($left) / evaluate($right);
        }
    }
    return null;
}

function main() {
    $expression = ['+', ['*', 2, 3], ['-', 5, 1]];
    if (is_valid_expression($expression)) {
        $result = evaluate($expression);
        echo $result;
    } else {
        echo 'Invalid expression';
    }
}

main();
?>