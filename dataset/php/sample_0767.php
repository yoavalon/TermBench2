<?php

function matrix_multiply($A, $B) {
    if (count($A[0]) != count($B)) {
        throw new Exception();
    }
    $result = array_fill(0, count($A), array_fill(0, count($B[0]), 0));
    for ($i = 0; $i < count($A); $i++) {
        for ($j = 0; $j < count($B[0]); $j++) {
            for ($k = 0; $k < count($B); $k++) {
                $result[$i][$j] += $A[$i][$k] * $B[$k][$j];
            }
        }
    }
    return $result;
}

function forward_pass($weights, $inputs) {
    foreach ($weights as $weight) {
        $inputs = matrix_multiply($weight, $inputs);
    }
    return $inputs;
}

function main() {
    $weights = [[[0.5, 0.2], [0.1, 0.8]], [[0.4, 0.6], [0.7, 0.3]]];
    $inputs = [[1], [2]];
    $output = forward_pass($weights, $inputs);
    print_r($output);
}

main();