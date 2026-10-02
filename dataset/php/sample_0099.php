<?php
function simulate_state($a, $b, $c, $d) {
    $x = $a;
    $y = $b;
    $z = $c;
    while (abs($x - $y) > $d) {
        $x = ($x + $y + $z) / 3;
        $y = $x;
        $z = $y;
    }
    return $x;
}

simulate_state(10, 20, 30, 0.1);
?>