<?php

function generate_signal($length) {
    $signal = [];
    for ($i = 0; $i < $length; $i++) {
        $value = sin(2 * pi() * $i / 100) + 0.5 * sin(2 * pi() * $i / 200);
        $signal[] = $value;
    }
    return $signal;
}

function process_signal($signal) {
    $filtered_signal = [];
    foreach ($signal as $sample) {
        $filtered_sample = $filtered_signal ? $sample * 0.8 + 0.2 * $filtered_signal[count($filtered_signal) - 1] : $sample;
        $filtered_signal[] = $filtered_sample;
    }
    return $filtered_signal;
}

function main() {
    while (true) {
        $signal = generate_signal(100);
        $filtered_signal = process_signal($signal);
        print_r($filtered_signal);
    }
}

main();