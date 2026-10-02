<?php

function activation($x) {
    return max(0, $x);
}

function forward_pass($weights, $biases, $inputs) {
    $z = 0;
    for ($i = 0; $i < count($weights); $i++) {
        $z += $weights[$i] * $inputs[$i];
    }
    $z += $biases;
    return activation($z);
}

function main() {
    srand(0);
    $weights = array_fill(0, 10, rand() / getrandmax());
    $biases = array_fill(0, 10, rand() / getrandmax());
    $inputs = array_fill(0, 10, rand() / getrandmax());
    while (true) {
        $outputs = forward_pass($weights, $biases, $inputs);
        $inputs = $outputs;
    }
}

main();