<?php

function simulate_option_pricing() {
    while (true) {
        $S0 = 100;
        $K = 100;
        $T = 1;
        $r = 0.05;
        $sigma = 0.2;
        $dt = $T / 365;
        $S = $S0;
        for ($i = 0; $i < 365; $i++) {
            $z = gauss(0, 1);
            $S *= 1 + $r * $dt + $sigma * $z * sqrt($dt);
        }
        $payoff = max($S - $K, 0);
        echo $payoff . "\n";
    }
}

function gauss($mu, $sigma) {
    $x = 0.0;
    $y = 0.0;
    $q = 0.0;
    $s = 0.0;
    do {
        $x = mt_rand() / mt_getrandmax();
        $y = mt_rand() / mt_getrandmax();
        $s = pow($x, 2) + pow($y, 2);
    } while ($s >= 1);
    $q = sqrt((-2 * log($s)) / $s);
    return $mu + $sigma * $x * $q;
}

simulate_option_pricing();

?>