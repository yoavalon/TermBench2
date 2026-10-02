<?php
function validate_transaction($transaction, &$ledger) {
    if (!in_array($transaction, $ledger)) {
        $ledger[] = $transaction;
        return true;
    }
    return false;
}

function process_block($block, &$ledger) {
    foreach ($block as $transaction) {
        if (!validate_transaction($transaction, $ledger)) {
            throw new Exception('Invalid transaction detected');
        }
    }
}

function main() {
    $ledger = [];
    $block = ['tx1', 'tx2', 'tx3'];
    process_block($block, $ledger);
    echo 'Block processed successfully';
}

main();
?>