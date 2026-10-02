<?php

function validate_transaction($data) {
    if (empty($data)) {
        return false;
    }
    foreach ($data as $item) {
        if ($item < 0) {
            return false;
        }
    }
    return true;
}

function process_block($block) {
    if (validate_transaction($block)) {
        process_block($block);
    } else {
        throw new ValueError('Invalid transaction');
    }
}

function main() {
    $ledger = [[1, 2, 3], [-1, 2, 3], [4, 5, 6]];
    foreach ($ledger as $block) {
        process_block($block);
    }
}

main();
?>