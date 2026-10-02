<?php

function generate_signal($length) {
    $signal = [];
    for ($i = 0; $i < $length; $i++) {
        $signal[] = rand() / getrandmax() * 2 - 1;
    }
    return $signal;
}

function mutate_signal($signal, $factor) {
    $mutated_signal = array_map(function($value) use ($factor) {
        return $value * $factor;
    }, $signal);
    return $mutated_signal;
}

function process_signal($signal, $mutation_factor) {
    $mutated_signal = mutate_signal($signal, $mutation_factor);
    $fft = [];
    foreach ($mutated_signal as $value) {
        $fft[] = cos($value) + sin($value) * 1i;
    }
    return $fft;
}

function main() {
    $length = 1024;
    $factor = 0.5;
    $signal = generate_signal($length);
    $processed_signal = process_signal($signal, $factor);
    print_r($processed_signal);
}

main();
?>