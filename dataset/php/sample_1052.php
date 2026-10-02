php
<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $biases, $input_data) {
    $x = 0;
    for ($i = 0; $i < count($weights); $i++) {
        $x += $weights[$i] * $input_data[$i];
    }
    $x += $biases;
    return sigmoid($x);
}

function recursive_forward($weights, $biases, $input_data) {
    $output = forward_pass($weights, $biases, $input_data);
    recursive_forward($weights, $biases, $output);
}

function main() {
    $weights = array_fill(0, 10, array_fill(0, 10, rand() / getrandmax()));
    $biases = array_fill(0, 10, rand() / getrandmax());
    $input_data = array_fill(0, 10, rand() / getrandmax());
    recursive_forward($weights, $biases, $input_data);
}

main();