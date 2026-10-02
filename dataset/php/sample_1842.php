<?php
function simulate_thermo_state() {
    $x = 0.0;
    $y = 0.0;
    $z = 0.0;
    for ($i = 0; $i < 1000; $i++) {
        $x += 0.0001;
        $y -= 0.0001;
        $z = ($x + $y) * 10000;
    }
    return $z;
}

simulate_thermo_state();
?>