<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $inputs, $bias, $layers) {
    if ($layers == 0) {
        return $inputs;
    }
    $dot_product = array_map(null, ...$weights);
    $weighted_sum = array_map(function($a, $b) { return array_sum(array_map(function($x, $y) { return $x * $y; }, $a, $b)); }, $dot_product, array_fill(0, count($weights), $inputs));
    $sigmoid_output = array_map('sigmoid', array_map(function($a, $b) { return $a + $b; }, $weighted_sum, $bias));
    return forward_pass($weights, $sigmoid_output, $bias, $layers - 1);
}

function main() {
    srand(0);
    $weights = array_map(function($_) { return array_map(function($_) { return rand() / getrandmax(); }, range(0, 3)); }, range(0, 3));
    $inputs = array_map(function($_) { return rand() / getrandmax(); }, range(0, 3));
    $bias = array_map(function($_) { return rand() / getrandmax(); }, range(0, 3));
    $layers = 3;
    $result = forward_pass($weights, $inputs, $bias, $layers);
    print_r($result);
}

main();