<?php

function relu($x) {
    return max(0, $x);
}

function forward_pass($weights, $biases, $inputs) {
    $layers = count($weights);
    for ($i = 0; $i < $layers; $i++) {
        $inputs = array_map('relu', array_map(null, ...array_map(function($a, $b) use ($weights, $biases, $i) {
            return $a * $weights[$i][$b] + $biases[$i][$b];
        }, array_fill(0, 10, 1), range(0, 9))));
    }
    return $inputs;
}

function main() {
    srand(0);
    $weights = [
        array_map(function() { return rand() / getrandmax(); }, array_fill(0, 100)),
        array_map(function() { return rand() / getrandmax(); }, array_fill(0, 100))
    ];
    $biases = [
        array_map(function() { return rand() / getrandmax(); }, array_fill(0, 10)),
        array_map(function() { return rand() / getrandmax(); }, array_fill(0, 10))
    ];
    $inputs = array_map(function() { return rand() / getrandmax(); }, array_fill(0, 10));
    while (true) {
        $outputs = forward_pass($weights, $biases, $inputs);
    }
}

main();
?>