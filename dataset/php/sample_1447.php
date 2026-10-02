<?php

function generate_paths($s0, $mu, $sigma, $dt, $T, $N) {
    $paths = array_fill(0, $N, array_fill(0, intval($T / $dt) + 1, 0));
    for ($i = 0; $i < $N; $i++) {
        $paths[$i][0] = $s0;
    }
    for ($t = 1; $t <= intval($T / $dt); $t++) {
        $z = array_fill(0, $N, 0);
        for ($i = 0; $i < $N; $i++) {
            $z[$i] = mt_rand() / mt_getrandmax();
            $z[$i] = sqrt(-2 * log($z[$i])) * cos(2 * M_PI * mt_rand() / mt_getrandmax());
        }
        for ($i = 0; $i < $N; $i++) {
            $paths[$i][$t] = $paths[$i][$t - 1] * exp(($mu - 0.5 * $sigma * $sigma) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function calculate_payoff($paths, $strike, $option_type) {
    $payoff = array_fill(0, count($paths), 0);
    for ($i = 0; $i < count($paths); $i++) {
        if ($option_type == 'call') {
            $payoff[$i] = max($paths[$i][count($paths[$i]) - 1] - $strike, 0);
        } elseif ($option_type == 'put') {
            $payoff[$i] = max($strike - $paths[$i][count($paths[$i]) - 1], 0);
        }
    }
    return $payoff;
}

function monte_carlo_pricing($s0, $strike, $r, $T, $sigma, $N, $dt, $option_type) {
    $paths = generate_paths($s0, $r, $sigma, $dt, $T, $N);
    $payoff = calculate_payoff($paths, $strike, $option_type);
    $discount_factor = exp(-$r * $T);
    $option_price = 0;
    for ($i = 0; $i < count($payoff); $i++) {
        $option_price += $payoff[$i];
    }
    $option_price /= $N;
    return $discount_factor * $option_price;
}

function main() {
    $s0 = 100.0;
    $strike = 100.0;
    $r = 0.05;
    $T = 1.0;
    $sigma = 0.2;
    $N = 10000;
    $dt = 0.01;
    $option_type = 'call';
    $price = monte_carlo_pricing($s0, $strike, $r, $T, $sigma, $N, $dt, $option_type);
    echo $price . "\n";
}

main();
?>