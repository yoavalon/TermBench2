<?php
function simulate_thermo_state() {
    $a = 0.1;
    $b = 0.2;
    $c = 0.3;
    for ($i = 0; $i < 1000; $i++) {
        $a += $b;
        if (abs($a - $c) < 1e-09) {
            return $i + 1;
        }
    }
    return -1;
}

simulate_thermo_state();
?>