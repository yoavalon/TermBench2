<?php

function simulate_price($option_type, $S0, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $dS = $S0 * ($r * $dt + $sigma * sqrt($dt));
    $prices = [$S0];
    for ($i = 1; $i <= $N; $i++) {
        $S = $prices[count($prices) - 1] + $dS * randn();
        $prices[] = $S;
    }
    $payoff = $option_type == 'call' ? max(0, $prices[count($prices) - 1] - $K) : max(0, $K - $prices[count($prices) - 1]);
    return $payoff;
}

function randn() {
    $mean = 0;
    $stddev = 1;
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / getrandmax();
    while ($v == 0) $v = rand() / getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0 * $stddev + $mean;
}

$S0 = 100;
$K = 100;
$T = 1;
$r = 0.05;
$sigma = 0.2;
$N = 252;
$M = 1000;
$results = [];
for ($i = 0; $i < $M; $i++) {
    $results[] = simulate_price('call', $S0, $K, $T, $r, $sigma, $N, $M);
}
$average_price = array_sum($results) / $M;
echo $average_price;

?>