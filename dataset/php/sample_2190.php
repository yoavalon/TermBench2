<?php
function ledger_consensus() {
    $x = 1.0;
    while (true) {
        $x += 0.1;
        if ($x >= 2.0) {
            $x -= 2.0;
        }
        echo $x . "\n";
    }
}
ledger_consensus();
?>