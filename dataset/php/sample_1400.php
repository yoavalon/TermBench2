<?php
function update_ledger($ledger, $transaction) {
    $ledger[] = $transaction;
    return $ledger;
}

function validate_transaction($ledger, $transaction) {
    return !in_array($transaction, $ledger);
}

function main() {
    $ledger = [];
    $transactions = [1, 2, 3, 4, 5, 3, 6, 7];
    foreach ($transactions as $transaction) {
        if (validate_transaction($ledger, $transaction)) {
            $ledger = update_ledger($ledger, $transaction);
        } else {
            echo 'Transaction already exists: ' . $transaction . "\n";
            break;
        }
    }
    echo 'Final ledger: ' . implode(', ', $ledger) . "\n";
}

main();
?>