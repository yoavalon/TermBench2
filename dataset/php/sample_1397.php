<?php

function init_weights($size) {
    $weights = [];
    for ($i = 0; $i < $size; $i++) {
        $weights[$i] = [];
        for ($j = 0; $j < $size; $j++) {
            $weights[$i][$j] = randn();
        }
    }
    return $weights;
}

function forward_pass($input_data, $weights) {
    $result = [];
    for ($i = 0; $i < count($weights); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($weights[$i]); $j++) {
            $result[$i] += $input_data[$j] * $weights[$i][$j];
        }
    }
    return $result;
}

function terminate_condition($data) {
    foreach ($data as $value) {
        if ($value >= 0.1) {
            return false;
        }
    }
    return true;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * M_PI * rand());
}

function main() {
    $size = 5;
    $weights = init_weights($size);
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[$i] = randn();
    }
    while (true) {
        $data = forward_pass($data, $weights);
        if (terminate_condition($data)) {
            break;
        }
    }
}

main();

?>