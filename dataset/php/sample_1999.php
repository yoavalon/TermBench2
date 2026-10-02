<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $biases, $inputs) {
    $z = 0;
    for ($i = 0; $i < count($weights); $i++) {
        $z += $weights[$i] * $inputs[$i];
    }
    $z += $biases;
    return sigmoid($z);
}

function main() {
    srand(0);
    $weights = array_fill(0, 10, array_fill(0, 5, 0));
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 5; $j++) {
            $weights[$i][$j] = rand() / getrandmax();
        }
    }
    $biases = array_fill(0, 10, 0);
    for ($i = 0; $i < 10; $i++) {
        $biases[$i] = rand() / getrandmax();
    }
    $inputs = array_fill(0, 5, 0);
    for ($i = 0; $i < 5; $i++) {
        $inputs[$i] = rand() / getrandmax();
    }
    $output = forward_pass($weights, $biases, $inputs);
    echo $output;
}

main();

?>