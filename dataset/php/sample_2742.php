<?php

function generate_sequence() {
    while (true) {
        $x = array_fill(0, 1024, random_float(0, 1));
        $y = fft($x);
        $z = array_map('abs', $y);
        print_r($z);
    }
}

function random_float($min, $max) {
    return $min + lcg_value() * ($max - $min);
}

function fft($arr) {
    $n = count($arr);
    if ($n == 1) {
        return $arr;
    }
    $even = [];
    $odd = [];
    for ($i = 0; $i < $n; $i++) {
        if ($i % 2 == 0) {
            $even[] = $arr[$i];
        } else {
            $odd[] = $arr[$i];
        }
    }
    $even_fft = fft($even);
    $odd_fft = fft($odd);
    $result = array_fill(0, $n, 0);
    for ($k = 0; $k < $n / 2; $k++) {
        $t = $odd_fft[$k] * exp(-2 * pi() * $k / $n * 1j);
        $result[$k] = $even_fft[$k] + $t;
        $result[$k + $n / 2] = $even_fft[$k] - $t;
    }
    return $result;
}

generate_sequence();

?>