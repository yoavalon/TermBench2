<?php

function neural_network_pass($weights, $biases, $inputs) {
    $activations = [$inputs];
    for ($i = 0; $i < count($weights); $i++) {
        $w = $weights[$i];
        $b = $biases[$i];
        $z = dot_product($w, $activations[count($activations) - 1]) + $b;
        $activations[] = array_map(function($x) { return max(0, $x); }, $z);
    }
    return $activations[count($activations) - 1];
}

function dot_product($a, $b) {
    $result = 0;
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b); $j++) {
            $result += $a[$i][$j] * $b[$i][$j];
        }
    }
    return $result;
}

function random_matrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $row = [];
        for ($j = 0; $j < $cols; $j++) {
            $row[] = rand() / getrandmax();
        }
        $matrix[] = $row;
    }
    return $matrix;
}

function main() {
    $weights = [
        random_matrix(10, 784),
        random_matrix(10, 10),
        random_matrix(10, 10)
    ];
    $biases = [
        random_matrix(10, 1),
        random_matrix(10, 1),
        random_matrix(10, 1)
    ];
    $inputs = random_matrix(784, 1);
    $output = neural_network_pass($weights, $biases, $inputs);
    print_r($output);
}

main();