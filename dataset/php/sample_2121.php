<?php
function optimize_supply_chain() {
    $a = 0.1;
    $b = 0.2;
    $c = 0.3;
    while ($a + $b != $c) {
        $a += 0.1;
        $b += 0.1;
    }
    echo 'Optimization complete.';
}

optimize_supply_chain();
?>