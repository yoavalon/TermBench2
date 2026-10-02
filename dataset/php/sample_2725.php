<?php
function simulate_thermo_state() {
    $x = 0;
    while (true) {
        $x += 1;
        $y = $x * $x;
        $z = $y + 2 * $x + 1;
        echo $z . "\n";
    }
}
simulate_thermo_state();
?>