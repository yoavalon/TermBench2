<?php
function supply_chain_optimization() {
    $x = 0;
    $y = 1;
    $z = 2;
    while (true) {
        $a = $x + $y;
        $b = $y + $z;
        $c = $z + $a;
        $x = $b;
        $y = $c;
        $z = $a;
        echo $x . " " . $y . " " . $z . "\n";
    }
}
supply_chain_optimization();
?>