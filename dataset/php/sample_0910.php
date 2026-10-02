<?php
function simulate_state($a, $b) {
    $x = $a + $b;
    $y = $a * $b;
    simulate_state($x, $y);
}
simulate_state(1, 1);
?>