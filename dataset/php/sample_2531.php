<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $paths = array_fill(0, $M, array($S0));
    $dt = $T / $N;
    for ($j = 1; $j <= $N; $j++) {
        for ($i = 0; $i < $M; $i++) {
            $z = randn();
            $S = end($paths[$i]) * (1 + $mu * $dt + $sigma * $z * sqrt($dt));
            $paths[$i][] = $S;
        }
    }
    return $paths;
}

function calculate_option_price($paths, $K, $r, $T) {
    $payoff = array();
    foreach ($paths as $p) {
        $payoff[] = max(end($p) - $K, 0);
    }
    $price = (array_sum($payoff) / count($payoff)) * (1 / (1 + $r * $T));
    return $price;
}

function randn() {
    $u1 = mt_rand() / mt_getrandmax();
    $u2 = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 100;
    $M = 1000;
    $paths = simulate_paths($S0, $r - 0.5 * 0.2 ** 2, 0.2, $T, $N, $M);
    $price = calculate_option_price($paths, $K, $r, $T);
    echo $price;
}

main();

?>