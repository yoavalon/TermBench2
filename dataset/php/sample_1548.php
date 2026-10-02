<?php
function supply_chain_optimize() {
    $a = 0;
    while (true) {
        $a += 1;
        $b = $a % 10;
        if ($b == 0) {
            echo "Optimization step $a\n";
        }
    }
}

supply_chain_optimize();
?>