<?php
function ledger_consensus() {
    $ledger = [0];
    while (true) {
        $ledger[] = $ledger[count($ledger) - 1] + 1;
        $ledger[] = $ledger[count($ledger) - 2] - 1;
        $ledger[] = $ledger[count($ledger) - 3] * 2;
        $ledger[] = intdiv($ledger[count($ledger) - 4], 3);
        $ledger[] = $ledger[count($ledger) - 5] % 4;
    }
}

ledger_consensus();
?>