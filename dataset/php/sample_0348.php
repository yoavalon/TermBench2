<?php
function simulate_state() {
    $x = 0;
    $y = 1;
    while (true) {
        $x = $y;
        $y = $x + $y;
    }
}
simulate_state();
?>