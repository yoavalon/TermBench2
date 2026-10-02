<?php

function simulate_option_price($S0, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S = $S0;
    for ($i = 0; $i < $N; $i++) {
        $S *= exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * gauss(0, 1));
    }
    return max($S - $K, 0);
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    $c = 0.0;
    do {
        $a = mt_rand() / mt_getrandmax();
        $b = mt_rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($a)) * cos(2.0 * M_PI * $b);
        $c = $mu + $sigma * $z;
    } while ($c <= 0.0);
    return $c;
}

function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $M, $N) {
    $total = 0;
    for ($i = 0; $i < $M; $i++) {
        $total += simulate_option_price($S0, $K, $T, $r, $sigma, $N);
    }
    return $total / $M * exp(-$r * $T);
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $M = 1000;
    $N = 100;
    echo monte_carlo_pricing($S0, $K, $T, $r, $sigma, $M, $N);
}

main();

?>