<?php
function simulate_thermodynamic_state($a, $b, $c, $d) {
    $x = $a;
    $y = $b;
    $z = $c;
    $w = $d;
    for ($i = 0; $i < 10; $i++) {
        list($x, $y, $z, $w) = array($x + $y, $y + $z, $z + $w, $w + $x);
    }
    return array($x, $y, $z, $w);
}

function main() {
    $result = simulate_thermodynamic_state(1, 1, 1, 1);
    print_r($result);
}
main();
?>