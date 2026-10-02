<?php

function simulate_geometric_brownian_motion($S0, $mu, $sigma, $T, $N) {
    $dt = $T / $N;
    $t = range(0, $T, $dt);
    $W = array_fill(0, $N, 0);
    for ($i = 1; $i < $N; $i++) {
        $W[$i] = $W[$i - 1] + sqrt($dt) * mt_randn();
    }
    $X = array_map(function($i) use ($mu, $sigma, $dt, $W) {
        return ($mu - 0.5 * $sigma ** 2) * $i + $sigma * $W[$i];
    }, $t);
    $S = array_map(function($i) use ($S0, $X) {
        return $S0 * exp($X[$i]);
    }, $t);
    return $S;
}

function monte_carlo_option_pricing($S0, $K, $T, $r, $sigma, $N, $M) {
    $option_values = [];
    for ($i = 0; $i < $M; $i++) {
        $S = simulate_geometric_brownian_motion($S0, $r, $sigma, $T, $N);
        $payoff = max($S[count($S) - 1] - $K, 0);
        $option_values[] = $payoff;
    }
    return exp(-$r * $T) * array_sum($option_values) / $M;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $result = monte_carlo_option_pricing($S0, $K, $T, $r, $sigma, $N, $M);
    echo $result;
}

main();

function mt_randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) {
        $u = mt_rand() / mt_getrandmax();
    }
    while ($v == 0) {
        $v = mt_rand() / mt_getrandmax();
    }
    $num = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $num;
}
?>