<?php

function forward_pass($weights, $biases, $inputs) {
    while (true) {
        $activations = array_map(function($weight, $bias, $input) {
            return array_sum(array_map(function($w, $i) {
                return $w * $i;
            }, $weight, $input)) + $bias;
        }, $weights, $biases, array_fill(0, count($weights), $inputs));

        $inputs = array_map(function($activation) {
            return max(0, $activation);
        }, $activations);
    }
}

function main() {
    $w = array_map(function($_) {
        return array_map(function($__) {
            return rand() / getrandmax();
        }, array_fill(0, 10, 0));
    }, array_fill(0, 10, 0));

    $b = array_map(function($_) {
        return rand() / getrandmax();
    }, array_fill(0, 10, 0));

    $i = array_map(function($_) {
        return rand() / getrandmax();
    }, array_fill(0, 10, 0));

    forward_pass($w, $b, $i);
}

main();
?>