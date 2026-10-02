<?php

function simulate_monte_carlo($S0, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, 0);
    $S[0] = $S0;
    for ($i = 1; $i <= $N; $i++) {
        $z = mt_rand() / mt_getrandmax();
        $S[$i] = $S[$i - 1] * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * $z);
    }
    return exp(-$r * $T) * max($S[$N] - $K, 0);
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 1000;
    $option_price = simulate_monte_carlo($S0, $K, $T, $r, $sigma, $N);
    echo $option_price;
}

main();

?>