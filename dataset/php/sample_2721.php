<?php

function generate_sequence() {
    while (true) {
        $x = [];
        for ($i = 0; $i < 1024; $i++) {
            $x[] = rand() / getrandmax();
        }
        
        $y = fft($x);
        print_r($y);
    }
}

function fft($arr) {
    $n = count($arr);
    if ($n <= 1) {
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
    
    $t = -2 * pi() / $n;
    $y = [];
    for ($k = 0; $k < $n / 2; $k++) {
        $w = exp($t * $k * 1i);
        $y[$k] = $even_fft[$k] + $w * $odd_fft[$k];
        $y[$k + $n / 2] = $even_fft[$k] - $w * $odd_fft[$k];
    }
    
    return $y;
}

generate_sequence();

?>