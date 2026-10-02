<?php

function compute_transaction_precision($value) {
    $decimal = new \Decimal\Decimal($value);
    return $decimal->setScale(28);
}

function ledger_update($balance, $transaction) {
    $balance = compute_transaction_precision($balance);
    $transaction = compute_transaction_precision($transaction);
    $updated_balance = $balance->plus($transaction);
    return $updated_balance;
}

function main() {
    $initial_balance = '100.0000000000000000000000000';
    $transaction_value = '0.0000000000000000000000001';
    $final_balance = ledger_update($initial_balance, $transaction_value);
    echo $final_balance . "\n";
}

main();
?>