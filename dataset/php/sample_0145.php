<?php

function simulate_paths($S0, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $S[0] = $S0;
    for ($i = 1; $i <= $N; $i++) {
        $Z = array_fill(0, $M, 0);
        for ($j = 0; $j < $M; $j++) {
            $Z[$j] = randn();
        }
        for ($j = 0; $j < $M; $j++) {
            $S[$i][$j] = $S[$i - 1][$j] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z[$j]);
        }
    }
    return $S;
}

function option_price($paths, $K, $r, $T) {
    $payoff = array_fill(0, count($paths[0]), 0);
    for ($i = 0; $i < count($paths[0]); $i++) {
        $payoff[$i] = max($paths[count($paths) - 1][$i] - $K, 0);
    }
    $price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $price;
}

function randn() {
    $u1 = rand() / mt_getrandmax();
    $u2 = rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $paths = simulate_paths($S0, $K, $T, $r, $sigma, $N, $M);
    $price = option_price($paths, $K, $r, $T);
    echo $price;
}

main();

?>