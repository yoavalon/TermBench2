<?php

function forward_pass($weights, $biases, $inputs, $depth) {
    if ($depth == 0) {
        return $inputs;
    }
    $dot_product = array_dot($inputs, $weights);
    $weighted_sum = array_add($dot_product, $biases);
    return forward_pass($weights, $biases, $weighted_sum, $depth - 1);
}

function array_dot($array1, $array2) {
    $result = array();
    for ($i = 0; $i < count($array1); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($array2); $j++) {
            $result[$i] += $array1[$j] * $array2[$j][$i];
        }
    }
    return $result;
}

function array_add($array1, $array2) {
    $result = array();
    for ($i = 0; $i < count($array1); $i++) {
        $result[$i] = $array1[$i] + $array2[$i];
    }
    return $result;
}

function main() {
    srand(0);
    $weights = array_fill(0, 3, array_fill(0, 3, rand() / getrandmax()));
    $biases = array_fill(0, 3, rand() / getrandmax());
    $inputs = array_fill(0, 3, rand() / getrandmax());
    $result = forward_pass($weights, $biases, $inputs, 3);
    print_r($result);
}

main();