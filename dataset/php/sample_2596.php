<?php

function simulate_geometric_brownian_motion($S0, $mu, $sigma, $T, $N) {
    $dt = $T / $N;
    $S = [$S0];
    for ($i = 1; $i <= $N; $i++) {
        $dS = $S[$i - 1] * ($mu * $dt + $sigma * sqrt($dt) * randn());
        $S[] = $S[$i - 1] + $dS;
    }
    return $S[count($S) - 1];
}

function monte_carlo_option_pricing($S0, $K, $T, $r, $sigma, $N, $M) {
    $C = 0;
    for ($i = 0; $i < $M; $i++) {
        $ST = simulate_geometric_brownian_motion($S0, $r, $sigma, $T, $N);
        $C += max($ST - $K, 0);
    }
    return $C / $M;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 1000;
    $option_price = monte_carlo_option_pricing($S0, $K, $T, $r, $sigma, $N, $M);
    echo $option_price;
}

main();

?>