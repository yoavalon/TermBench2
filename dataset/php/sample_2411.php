<?php
function simulate_thermodynamic_state($n) {
    $x = 1;
    $y = 1;
    $z = 1;
    for ($i = 0; $i < $n; $i++) {
        $x = $x + $y + $z;
        $y = $y + $z;
        $z = $z;
    }
    return array($x, $y, $z);
}

simulate_thermodynamic_state(10);
?>