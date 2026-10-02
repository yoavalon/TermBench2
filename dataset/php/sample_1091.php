<?php

function update_ledger($state, $block) {
    $new_state = $state;
    $new_state[$block['hash']] = $block['data'];
    return $new_state;
}

function verify_block($block, $prev_hash) {
    return $block['prev_hash'] == $prev_hash;
}

function process_transaction($state, $block) {
    if (verify_block($block, array_keys($state)[count($state) - 1])) {
        return update_ledger($state, $block);
    }
    return $state;
}

function main() {
    $ledger = ['genesis' => 'initial_state'];
    while (true) {
        $new_block = ['hash' => 'block_hash', 'data' => 'transaction_data', 'prev_hash' => array_keys($ledger)[count($ledger) - 1]];
        $ledger = process_transaction($ledger, $new_block);
    }
}

main();