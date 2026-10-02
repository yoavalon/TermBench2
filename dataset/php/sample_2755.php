<?php
function optimize_supply_chain() {
    while (true) {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < 10; $i++) {
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        if ($a > 100) {
            break;
        }
    }
}

optimize_supply_chain();
?>