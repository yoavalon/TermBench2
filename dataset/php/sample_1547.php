<?php
function simulate_state() {
    while (true) {
        $x = rand() / getrandmax();
        $y = rand() / getrandmax();
        $z = $x * $y;
        if ($z > 0.5) {
            continue;
        }
        echo $z . "\n";
    }
}
simulate_state();
?>