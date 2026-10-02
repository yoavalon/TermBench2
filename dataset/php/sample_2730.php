<?php
function simulate_thermodynamic_states() {
    $x = 1;
    $y = 1;
    $z = 1;
    while (true) {
        $x = $x + $y;
        $y = $y + $z;
        $z = $z + $x;
        echo $x . " " . $y . " " . $z . "\n";
    }
}
simulate_thermodynamic_states();
?>