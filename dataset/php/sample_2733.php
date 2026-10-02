<?php
function supply_chain_optimization() {
    while (true) {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < 100; $i++) {
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        echo $b . "\n";
    }
}
supply_chain_optimization();
?>