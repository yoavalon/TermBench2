<?php

function monte_carlo_pricing($S, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array($S));
    for ($i = 1; $i <= $N; $i++) {
        for ($j = 0; $j < $M; $j++) {
            $paths[$j][] = $paths[$j][count($paths[$j]) - 1] * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * mt_randn());
        }
    }
    $sum = 0;
    for ($j = 0; $j < $M; $j++) {
        $sum += max($paths[$j][count($paths[$j]) - 1] - $K, 0);
    }
    return exp(-$r * $T) * $sum / $M;
}

function mt_randn() {
    $mu = 0;
    $sigma = 1;
    $randn = sqrt(-2 * log(mt_rand() / mt_getrandmax())) * cos(2 * M_PI * mt_rand() / mt_getrandmax());
    return $mu + $sigma * $randn;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);

?>