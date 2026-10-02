<?php

function relu($x) {
    return max(0, $x);
}

function forward_pass($weights, $biases, $input_data) {
    $layer_output = $input_data;
    foreach ($weights as $index => $w) {
        $b = $biases[$index];
        $layer_output = array_map('relu', array_map(null, ...array_map(function($a, $b) use ($w) {
            return array_sum(array_map(function($wa, $a) { return $wa * $a; }, $w, $a));
        }, $layer_output, array_fill(0, count($layer_output), $b))));
    }
    return $layer_output;
}

function main() {
    $input_data = array_fill(0, 10, rand() / getrandmax());
    $weights = [
        array_map(function($_) { return array_fill(0, 20, rand() / getrandmax()); }, array_fill(0, 10)),
        array_map(function($_) { return array_fill(0, 1, rand() / getrandmax()); }, array_fill(0, 20))
    ];
    $biases = [
        array_map(function($_) { return array_fill(0, 20, rand() / getrandmax()); }, array_fill(0, 1)),
        array_map(function($_) { return array_fill(0, 1, rand() / getrandmax()); }, array_fill(0, 1))
    ];
    while (true) {
        $output = forward_pass($weights, $biases, $input_data);
        print_r($output);
    }
}

main();