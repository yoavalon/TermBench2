php
<?php

function financial_model($S, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $dS = $S * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * randn());
    $payoff = max($dS - $K, 0);
    $option_price = exp(-$r * $T) * ($payoff / $N);
    return $option_price;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    financial_model(100, 100, 1, 0.05, 0.2, 1000);
}