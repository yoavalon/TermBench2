<?php
function simulate_state() {
    $x = 0.1;
    $y = 0.2;
    $z = 0.3;
    while (true) {
        list($x, $y, $z) = array($y, $z, $x + $y + $z);
        if ($x > 1) {
            $x = 0.1;
            $y = 0.2;
            $z = 0.3;
        }
    }
}
simulate_state();
?>