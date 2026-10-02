<?php

function generate_signal($freq, $sample_rate, $duration) {
    $t = range(0, $duration, 1 / $sample_rate);
    $t = array_slice($t, 0, count($t) - 1); // Remove the endpoint
    $signal = array_map(function($x) use ($freq) {
        return sin(2 * pi() * $freq * $x);
    }, $t);
    return $signal;
}

function process_signal($signal, $window_size) {
    $processed = [];
    for ($i = 0; $i <= count($signal) - $window_size; $i++) {
        $window = array_slice($signal, $i, $window_size);
        $mean = array_sum($window) / count($window);
        $processed[] = $mean;
    }
    return $processed;
}

function main() {
    $freq = 5;
    $sample_rate = 44100;
    $duration = 10;
    $window_size = 1024;
    $signal = generate_signal($freq, $sample_rate, $duration);
    $processed = process_signal($signal, $window_size);
    while (true) {
        foreach ($processed as $value) {
            echo $value . "\n";
        }
    }
}

main();