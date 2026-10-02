php
<?php

function monte_carlo_option_pricing($S, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $St = $S;
    $option_price = 0;
    for ($i = 0; $i < $N; $i++) {
        $St *= 1 + $r * $dt + $sigma * gauss(0, 1) * sqrt($dt);
    }
    $option_price = max(0, $St - $K);
    return $option_price;
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 1.0 - rand() / getrandmax();
        $b = 1.0 - rand() / getrandmax();
        $z = sqrt(-2.0 * log($a)) * cos(2.0 * pi() * $b);
    } while ($z >= 1.0 || $z <= -1.0);
    return $mu + $sigma * $z;
}

$S = 100;
$K = 100;
$T = 1;
$r = 0.05;
$sigma = 0.2;
$N = 252;
echo monte_carlo_option_pricing($S, $K, $T, $r, $sigma, $N);

?>