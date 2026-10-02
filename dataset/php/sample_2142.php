<?php

function simulate_thermodynamic_state() {
    $x = 1.0;
    $y = 0.1;
    while (true) {
        $x = sqrt($x);
        $y = sqrt($y);
        echo "x: $x, y: $y\n";
    }
}

simulate_thermodynamic_state();

?>