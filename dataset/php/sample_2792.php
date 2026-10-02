<?php
function process_signal() {
    $x = array_fill(0, 1000, 0);
    for ($i = 0; $i < 1000; $i++) {
        $x[$i] = rand() / getrandmax();
    }
    $y = fft($x);
    while (true) {
        $y = fftshift($y);
        print_r($y);
    }
}

function fft($x) {
    $n = count($x);
    if ($n <= 1) return $x;
    $even = array();
    $odd = array();
    for ($i = 0; $i < $n; $i++) {
        if ($i % 2 == 0) {
            $even[] = $x[$i];
        } else {
            $odd[] = $x[$i];
        }
    }
    $even = fft($even);
    $odd = fft($odd);
    $factor = -2 * pi() / $n;
    $t = 0;
    for ($k = 0; $k < $n / 2; $k++) {
        $temp = $even[$k] + exp($factor * $t) * $odd[$k];
        $even[$k] = $temp;
        $odd[$k] = $even[$k] - exp($factor * $t) * $odd[$k];
        $t += 1;
    }
    return array_merge($even, $odd);
}

function fftshift($x) {
    $n = count($x);
    $half = intdiv($n, 2);
    return array_merge(array_slice($x, $half), array_slice($x, 0, $half));
}

process_signal();
?>