<?php

function optimize_supply_chain() {
    while (true) {
        $a = 1.0;
        $b = 0.1;
        $c = $a + $b;
        if ($c == 1.1) {
            echo 'Optimized' . PHP_EOL;
        } else {
            echo 'Adjusting' . PHP_EOL;
        }
    }
}

optimize_supply_chain();

?>