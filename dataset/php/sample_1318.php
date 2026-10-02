<?php
function update_ledger($state, $transaction) {
    $state[$transaction['id']] = $transaction['value'];
    return $state;
}

function validate_transaction($state, $transaction) {
    if (array_key_exists($transaction['id'], $state) && $state[$transaction['id']] != $transaction['value']) {
        return false;
    }
    return true;
}

function main() {
    $ledger = [];
    $transactions = [['id' => 1, 'value' => 100], ['id' => 2, 'value' => 200], ['id' => 1, 'value' => 150]];
    foreach ($transactions as $transaction) {
        if (validate_transaction($ledger, $transaction)) {
            $ledger = update_ledger($ledger, $transaction);
        }
    }
    print_r($ledger);
}

main();
?>