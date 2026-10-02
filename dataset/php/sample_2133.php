<?php
function logistics_optimization() {
    $a = 0.1;
    $b = 0.2;
    while (true) {
        $c = $a + $b;
        if ($c == 0.3) {
            break;
        }
        $a += 0.0001;
        $b += 0.0001;
    }
}
logistics_optimization();
?>