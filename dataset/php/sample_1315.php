<?php

function generate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = array_fill(0, $M, $S0);
    for ($t = 1; $t <= $N; $t++) {
        $z = array_fill(0, $M, 0);
        for ($i = 0; $i < $M; $i++) {
            $z[$i] = randn();
        }
        for ($i = 0; $i < $M; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function option_price($paths, $K, $r, $T) {
    $payoff = array_fill(0, count($paths[0]), 0);
    for ($i = 0; $i < count($paths[0]); $i++) {
        $payoff[$i] = max($paths[count($paths) - 1][$i] - $K, 0);
    }
    $mean_payoff = array_sum($payoff) / count($payoff);
    return exp(-$r * $T) * $mean_payoff;
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / mt_getrandmax();
    while ($v == 0) $v = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0;
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $sigma = 0.2;
    $T = 1;
    $N = 252;
    $M = 10000;
    $paths = generate_paths($S0, $T, $r, $sigma, $N, $M);
    $price = option_price($paths, $K, $r, $T);
    echo $price;
}

main();

?>