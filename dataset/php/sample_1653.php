<?php

function simulate_stock_price($S0, $mu, $sigma, $T, $dt) {
    $S = $S0;
    for ($i = 0; $i < intdiv($T, $dt); $i++) {
        $dS = $mu * $S * $dt + $sigma * $S * gauss(0, 1) * sqrt($dt);
        $S += $dS;
    }
    return $S;
}

function monte_carlo_option_price($S0, $K, $T, $r, $sigma, $N, $dt) {
    $option_price = 0;
    for ($i = 0; $i < $N; $i++) {
        $S_T = simulate_stock_price($S0, $r, $sigma, $T, $dt);
        $option_price += max($S_T - $K, 0);
    }
    return $option_price * (1 / $N) * exp(-$r * $T);
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2 * rand() - 1;
        $b = 2 * rand() - 1;
        $z = $a * $a + $b * $b;
    } while ($z >= 1);
    return $mu + $sigma * $a * sqrt(-2 * log($z) / $z);
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100000;
    $dt = 0.01;
    $price = monte_carlo_option_price($S0, $K, $T, $r, $sigma, $N, $dt);
    echo "Option Price: " . $price . "\n";
}

main();