<?php

function generate_data($size) {
    $data = [];
    $labels = [];
    for ($i = 0; $i < $size; $i++) {
        $data[$i] = array_fill(0, $size, mt_rand() / mt_getrandmax());
        $labels[$i] = mt_rand(0, 1);
    }
    return [$data, $labels];
}

function forward_pass($data, $weights, $bias) {
    $linear_output = [];
    for ($i = 0; $i < count($data); $i++) {
        $linear_output[$i] = 0;
        for ($j = 0; $j < count($data[$i]); $j++) {
            $linear_output[$i] += $data[$i][$j] * $weights[$i][$j];
        }
        $linear_output[$i] += $bias[$i];
        $linear_output[$i] = max(0, $linear_output[$i]);
    }
    return $linear_output;
}

function main() {
    $size = 100;
    list($data, $labels) = generate_data($size);
    $weights = [];
    $bias = [];
    for ($i = 0; $i < $size; $i++) {
        $weights[$i] = array_fill(0, $size, mt_rand() / mt_getrandmax());
        $bias[$i] = mt_rand() / mt_getrandmax();
    }
    while (true) {
        $activations = forward_pass($data, $weights, $bias);
    }
}

main();

?>