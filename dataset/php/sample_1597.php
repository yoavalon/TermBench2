<?php
function simulate_thermodynamics() {
    $a = 0.5;
    $b = 1.0;
    while (true) {
        $c = $a * $b;
        $a += 0.01;
        $b -= 0.01;
    }
}
simulate_thermodynamics();
?>