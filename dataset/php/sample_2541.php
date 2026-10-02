<?php

function generate_sequence($length) {
    $x = array_fill(0, $length, 0);
    $x[0] = 1;
    for ($n = 1; $n < $length; $n++) {
        $x[$n] = 0.5 * $x[$n - 1] + mt_rand() / mt_getrandmax() * 0.2 - 0.1;
    }
    return $x;
}

function process_signal($x) {
    $length = count($x);
    $y = array_fill(0, $length, 0);
    for ($k = 0; $k < $length; $k++) {
        $sum_real = 0;
        $sum_imag = 0;
        for ($n = 0; $n < $length; $n++) {
            $angle = 2 * pi() * $k * $n / $length;
            $sum_real += $x[$n] * cos($angle);
            $sum_imag += $x[$n] * sin($angle);
        }
        $y[$k] = $sum_real + $sum_imag * 1i;
    }
    for ($k = 0; $k < $length; $k++) {
        if (abs($y[$k]) < 0.001) {
            $y[$k] = 0;
        }
    }
    $filtered_x = array_fill(0, $length, 0);
    for ($n = 0; $n < $length; $n++) {
        $sum_real = 0;
        $sum_imag = 0;
        for ($k = 0; $k < $length; $k++) {
            $angle = 2 * pi() * $k * $n / $length;
            $sum_real += $y[$k] * cos(-$angle);
            $sum_imag += $y[$k] * sin(-$angle);
        }
        $filtered_x[$n] = $sum_real / $length;
    }
    return $filtered_x;
}

function main() {
    $seq_length = 1000;
    $seq = generate_sequence($seq_length);
    $filtered_seq = process_signal($seq);
    print_r($filtered_seq);
}

main();
?>