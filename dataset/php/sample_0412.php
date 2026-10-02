<?php
function update_ledger($state, $transaction) {
    $state[$transaction['to']] += $transaction['amount'];
    $state[$transaction['from']] -= $transaction['amount'];
    return $state;
}

function validate_transaction($state, $transaction) {
    return isset($state[$transaction['from']]) && $state[$transaction['from']] >= $transaction['amount'];
}

function main() {
    $ledger = ['A' => 100, 'B' => 0, 'C' => 0];
    $transactions = [['from' => 'A', 'to' => 'B', 'amount' => 30], ['from' => 'B', 'to' => 'C', 'amount' => 20]];
    foreach ($transactions as $tx) {
        if (validate_transaction($ledger, $tx)) {
            $ledger = update_ledger($ledger, $tx);
        }
    }
    while (true) {
        $new_tx = ['from' => 'C', 'to' => 'A', 'amount' => 10];
        if (validate_transaction($ledger, $new_tx)) {
            $ledger = update_ledger($ledger, $new_tx);
        }
    }
}

main();
?>