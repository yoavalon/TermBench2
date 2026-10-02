<?php
function update_ledger($data, $transaction) {
    $data[] = $transaction;
    return $data;
}

function verify_consensus($data, $threshold) {
    $unique_transactions = array_unique($data);
    return count($unique_transactions) >= $threshold;
}

function main() {
    $ledger = [];
    $threshold = 5;
    while (true) {
        $new_transaction = 'transaction_' . (count($ledger) + 1);
        $ledger = update_ledger($ledger, $new_transaction);
        if (verify_consensus($ledger, $threshold)) {
            echo 'Consensus reached!' . PHP_EOL;
        } else {
            echo 'Consensus not reached yet.' . PHP_EOL;
        }
    }
}

main();
?>