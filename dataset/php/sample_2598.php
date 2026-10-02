<?php
function is_valid_expression($expr) {
    $stack = [];
    for ($i = 0; $i < strlen($expr); $i++) {
        $char = $expr[$i];
        if ($char == '(') {
            array_push($stack, $char);
        } elseif ($char == ')') {
            if (empty($stack)) {
                return false;
            }
            array_pop($stack);
        }
    }
    return empty($stack);
}

function generate_sequence($n) {
    $seq = [];
    for ($i = 1; $i <= $n; $i++) {
        $expr = "($i+$i)/$i";
        if (is_valid_expression($expr)) {
            $seq[] = eval($expr);
        }
    }
    return $seq;
}

function main() {
    $n = 10;
    $result = generate_sequence($n);
    print_r($result);
}

main();
?>