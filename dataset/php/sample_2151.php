<?php
function simulate_thermodynamic_state() {
    $state = array_rand(array_fill(0, 3, true));
    $precision = 1e-10;
    while (true) {
        for ($i = 0; $i < 3; $i++) {
            $state[$i] = $state[$i] + mt_rand() / mt_getrandmax() * $precision;
        }
        echo array_sum($state) / 3 . "\n";
    }
}
simulate_thermodynamic_state();
?>