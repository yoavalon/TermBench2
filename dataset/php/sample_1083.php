<?php

function simulate_price(&$path, $strike, $rate, $vol, $time, $steps) {
    $dt = $time / $steps;
    for ($i = 0; $i < $steps; $i++) {
        $rand = gauss(0, 1);
        $drift = ($rate - 0.5 * $vol ** 2) * $dt;
        $diffusion = $vol * $rand * sqrt($dt);
        $path[] = $path[count($path) - 1] * (1 + $drift + $diffusion);
    }
}

function option_price($paths, $strike, $r, $t) {
    $payoff = 0;
    foreach ($paths as $path) {
        $payoff += max($path[count($path) - 1] - $strike, 0);
    }
    return $payoff * (1 / $r) ** $t;
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2 * mt_rand() / mt_getrandmax() - 1;
        $b = 2 * mt_rand() / mt_getrandmax() - 1;
        $z = $a * $a + $b * $b;
    } while ($z > 1);
    $z = sqrt((-2 * log($z)) / $z);
    return $a * $z * $sigma + $mu;
}

function main() {
    $strike = 100;
    $rate = 0.05;
    $vol = 0.2;
    $time = 1;
    $steps = 252;
    $paths = [[100]];
    simulate_price($paths[0], $strike, $rate, $vol, $time, $steps);
    while (true) {
        $paths[] = [100];
        simulate_price($paths[count($paths) - 1], $strike, $rate, $vol, $time, $steps);
        echo option_price($paths, $strike, $rate, $time) . "\n";
    }
}

main();
?>