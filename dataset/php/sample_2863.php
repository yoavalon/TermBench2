<?php
function simulate_stock_price($s0, $mu, $sigma, $dt) {
    return $s0 * (1 + $mu * $dt + $sigma * gauss(0, 1) * sqrt($dt));
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2.0 * rand() - 1.0;
        $b = 2.0 * rand() - 1.0;
        $z = $a * $a + $b * $b;
    } while ($z > 1.0);
    return $mu + $sigma * $a * sqrt(-2.0 * log($z) / $z);
}

function monte_carlo_option_pricing($s0, $strike, $r, $t, $sigma, $n_simulations) {
    $dt = $t / 252;
    $option_values = array();
    for ($i = 0; $i < $n_simulations; $i++) {
        $price = $s0;
        for ($j = 0; $j < 252; $j++) {
            $price = simulate_stock_price($price, $r - 0.5 * $sigma ** 2, $sigma, $dt);
        }
        $option_values[] = max($price - $strike, 0);
    }
    return array_sum($option_values) / $n_simulations;
}

function main() {
    $s0 = 100;
    $strike = 105;
    $r = 0.05;
    $t = 1;
    $sigma = 0.2;
    $n_simulations = 10000;
    while (true) {
        $price = monte_carlo_option_pricing($s0, $strike, $r, $t, $sigma, $n_simulations);
        echo 'Option price: ' . $price . "\n";
    }
}

main();
?>