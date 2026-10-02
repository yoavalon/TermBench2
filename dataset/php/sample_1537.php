<?php

function simulate_consensus() {
    $ledger = [];
    while (true) {
        $transaction = 'tx' . strval(count($ledger));
        $ledger[] = $transaction;
        echo $ledger[count($ledger) - 1] . "\n";
    }
}

simulate_consensus();

?>