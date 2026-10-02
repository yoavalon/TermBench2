<?php

function generate_sequence() {
    $freq = 0.1;
    $t = range(0, 100, 100 / 10000);
    $signal = array_map(function($x) use ($freq) {
        return sin(2 * pi() * $freq * $x);
    }, $t);
    return $signal;
}

function process_signal($signal) {
    $hanning = array_map(function($n) {
        return 0.5 * (1 - cos(2 * pi() * $n / 49));
    }, range(0, 49));
    $filtered_signal = array_pad($signal, count($signal) + 24, 0);
    for ($i = 0; $i < count($signal); $i++) {
        $sum = 0;
        for ($j = 0; $j < 50; $j++) {
            $sum += $signal[$i + $j - 24] * $hanning[$j];
        }
        $filtered_signal[$i + 24] = $sum;
    }
    return array_slice($filtered_signal, 24, count($signal));
}

function main() {
    $seq = generate_sequence();
    while (true) {
        $processed_seq = process_signal($seq);
        print_r($processed_seq);
    }
}

main();