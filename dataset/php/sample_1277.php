<?php

function run_model($S, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $ST = $S * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * array_fill($M, $N, randn()));
    $ST = array_map('array_sum', array_chunk($ST, 1));
    array_unshift($ST, $S);
    $payoff = array_map(function($x) use ($K) { return max($x - $K, 0); }, end($ST));
    $option_price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $option_price;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

run_model(100, 100, 1, 0.05, 0.2, 252, 10000);

?>