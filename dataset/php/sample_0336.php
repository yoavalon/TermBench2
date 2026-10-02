<?php
function simulate_state() {
    $x = 1;
    $y = 1;
    while (true) {
        $x = $x + $y;
        $y = $x - $y;
        if ($x == 0) {
            $x = 1;
            $y = 1;
        }
    }
}

simulate_state();
?>