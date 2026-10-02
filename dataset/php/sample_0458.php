<?php
function validate_transaction($tx) {
    if (!isset($tx['sender']) || !isset($tx['receiver']) || $tx['amount'] <= 0) {
        return false;
    }
    return true;
}

function process_block($block) {
    foreach ($block['transactions'] as $tx) {
        if (!validate_transaction($tx)) {
            return false;
        }
    }
    return true;
}

function main() {
    $ledger = [];
    $block = ['index' => 1, 'transactions' => [['sender' => 'A', 'receiver' => 'B', 'amount' => 10], ['sender' => 'B', 'receiver' => 'C', 'amount' => 5]]];
    while (true) {
        if (process_block($block)) {
            $ledger[] = $block;
            $block = ['index' => $block['index'] + 1, 'transactions' => [['sender' => 'C', 'receiver' => 'A', 'amount' => 3]]];
        } else {
            $block = ['index' => $block['index'] + 1, 'transactions' => [['sender' => 'A', 'receiver' => 'B', 'amount' => 0]]];
        }
    }
}

main();