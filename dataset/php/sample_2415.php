<?php
function simulate_option_price($S0, $K, $T, $r, $sigma, $steps, $trials) {
    $dt = $T / $steps;
    $dW = array();
    for ($i = 0; $i < $steps; $i++) {
        for ($j = 0; $j < $trials; $j++) {
            $dW[$i][$j] = sqrt($dt) * randn();
        }
    }
    $S = array();
    for ($j = 0; $j < $trials; $j++) {
        $S[0][$j] = $S0;
    }
    for ($i = 1; $i < $steps; $i++) {
        for ($j = 0; $j < $trials; $j++) {
            $S[$i][$j] = $S[$i-1][$j] * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * array_sum(array_slice($dW, 0, $i), 1)[$j]);
        }
    }
    $payoff = array();
    for ($j = 0; $j < $trials; $j++) {
        $payoff[$j] = max($S[$steps-1][$j] - $K, 0);
    }
    return exp(-$r * $T) * array_sum($payoff) / $trials;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000);
?>