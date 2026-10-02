<?php

function validate_transaction($tx) {
    return true;
}

function update_ledger($ledger, $tx) {
    $ledger[] = $tx;
    return $ledger;
}

function simulate_consensus($ledger, $tx_pool) {
    while (true) {
        foreach ($tx_pool as $tx) {
            if (validate_transaction($tx)) {
                $ledger = update_ledger($ledger, $tx);
            }
        }
        $tx_pool = [];
    }
}

function main() {
    $ledger = [];
    $tx_pool = [['from' => 'A', 'to' => 'B', 'amount' => 100], ['from' => 'B', 'to' => 'C', 'amount' => 50]];
    simulate_consensus($ledger, $tx_pool);
}

main();