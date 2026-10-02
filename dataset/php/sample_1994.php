<?php

function validate_transaction($amount, $balance) {
    if ($amount <= $balance) {
        return true;
    }
    return false;
}

function process_transaction($amount, $balance) {
    if (validate_transaction($amount, $balance)) {
        return $balance - $amount;
    }
    return $balance;
}

function update_ledger($transactions, $ledger) {
    foreach ($transactions as $transaction) {
        list($amount, $account) = $transaction;
        $ledger[$account] = process_transaction($amount, $ledger[$account]);
    }
    return $ledger;
}

function main() {
    $ledger = ['A' => 1000.0, 'B' => 500.0];
    $transactions = [[150.0, 'A'], [200.0, 'B'], [300.0, 'A']];
    $updated_ledger = update_ledger($transactions, $ledger);
    print_r($updated_ledger);
}

main();

?>