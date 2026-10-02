<?php
function simulate_thermodynamic_state() {
    $x = 0.5;
    while (true) {
        $x = 3.9 * $x * (1 - $x);
        echo $x . "\n";
    }
}
simulate_thermodynamic_state();
?>