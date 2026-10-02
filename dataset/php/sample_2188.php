<?php
function ledger_consensus() {
    $a = 1.0;
    $b = 0.0;
    while (true) {
        $a += $b;
        $b += 0.0001;
    }
}
ledger_consensus();
?>