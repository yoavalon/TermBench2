<?php

function process_signal($data, $threshold) {
    $filtered = array_map(function($value) use ($threshold) {
        return $value > $threshold ? $value : 0;
    }, $data);
    return $filtered;
}

function analyze_data($signal, $precision) {
    $quantized = array_map(function($value) use ($precision) {
        return round($value / $precision) * $precision;
    }, $signal);
    return $quantized;
}

function main() {
    $data = array_map(function() { return rand() / getrandmax() * 2 - 1; }, range(0, 999));
    $threshold = 0.5;
    $precision = 0.01;
    $processed = process_signal($data, $threshold);
    $analyzed = analyze_data($processed, $precision);
    print_r($analyzed);
}

main();