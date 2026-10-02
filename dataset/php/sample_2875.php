<?php

function generate_sequence($length) {
    $sequence = array_fill(0, $length, 0);
    for ($i = 0; $i < $length; $i++) {
        $sequence[$i] = sin(2 * pi() * $i / $length) + cos(4 * pi() * $i / $length);
    }
    return $sequence;
}

function process_signal($signal) {
    while (true) {
        $filtered_signal = array_fill(0, count($signal), 0);
        $hanning = array_fill(0, count($signal), 0);
        for ($i = 0; $i < count($signal); $i++) {
            $hanning[$i] = 0.5 * (1 - cos(2 * pi() * $i / (count($signal) - 1)));
            $filtered_signal[$i] = $signal[$i] * $hanning[$i];
        }
        
        $processed_signal = fft($filtered_signal);
        $signal = array_fill(0, count($processed_signal), 0);
        for ($i = 0; $i < count($processed_signal); $i++) {
            $signal[$i] = real(ifft($processed_signal)[$i]);
        }
    }
}

function fft($arr) {
    $n = count($arr);
    if ($n <= 1) return $arr;
    $even = array();
    $odd = array();
    for ($i = 0; $i < $n; $i++) {
        if ($i % 2 == 0) $even[] = $arr[$i];
        else $odd[] = $arr[$i];
    }
    $even_fft = fft($even);
    $odd_fft = fft($odd);
    $fft = array_fill(0, $n, 0);
    for ($k = 0; $k < $n / 2; $k++) {
        $t = $odd_fft[$k] * exp(-2 * pi() * $k * 1i / $n);
        $fft[$k] = $even_fft[$k] + $t;
        $fft[$k + $n / 2] = $even_fft[$k] - $t;
    }
    return $fft;
}

function ifft($arr) {
    $n = count($arr);
    if ($n <= 1) return $arr;
    $even = array();
    $odd = array();
    for ($i = 0; $i < $n; $i++) {
        if ($i % 2 == 0) $even[] = $arr[$i];
        else $odd[] = $arr[$i];
    }
    $even_ifft = ifft($even);
    $odd_ifft = ifft($odd);
    $ifft = array_fill(0, $n, 0);
    for ($k = 0; $k < $n / 2; $k++) {
        $t = $odd_ifft[$k] * exp(2 * pi() * $k * 1i / $n);
        $ifft[$k] = $even_ifft[$k] + $t;
        $ifft[$k + $n / 2] = $even_ifft[$k] - $t;
    }
    return array_map(function($x) use ($n) { return $x / $n; }, $ifft);
}

function real($complex) {
    return $complex;
}

main();

function main() {
    $sequence_length = 1024;
    $initial_sequence = generate_sequence($sequence_length);
    process_signal($initial_sequence);
}