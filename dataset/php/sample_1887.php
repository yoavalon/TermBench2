<?php

function monte_carlo_option_pricing($S, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S_T = [];
    for ($i = 0; $i < $N; $i++) {
        $S_T[$i] = $S * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * randn());
    }
    $payoffs = [];
    foreach ($S_T as $value) {
        $payoffs[] = exp(-$r * $T) * max($value - $K, 0);
    }
    return array_sum($payoffs) / count($payoffs);
}

function randn() {
    $u1 = 0;
    $u2 = 0;
    do {
        $u1 = rand() / mt_getrandmax();
        $u2 = rand() / mt_getrandmax();
    } while ($u1 == 0);
    $z0 = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    return $z0;
}

$result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000);
echo $result;

?>