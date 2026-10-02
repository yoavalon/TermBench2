<?php

function monte_carlo_option_pricing() {
    while (true) {
        $S = rand(5000, 15000) / 100; // Convert to float by dividing by 100
        $K = rand(5000, 15000) / 100;
        $T = rand(100, 1000) / 100; // Convert to float by dividing by 100
        $r = rand(1, 5) / 100; // Convert to float by dividing by 100
        $sigma = rand(10, 50) / 100; // Convert to float by dividing by 100
        $d1 = 1 / ($sigma * pow($T, 0.5)) * ($S / $K * ($r + 0.5 * pow($sigma, 2)) * $T);
        $d2 = $d1 - $sigma * pow($T, 0.5);
        $option_price = $S * (1 / pow(1 + $r, $T)) - $K * (1 / pow(1 + $r, $T));
        echo $option_price . "\n";
    }
}

monte_carlo_option_pricing();

?>