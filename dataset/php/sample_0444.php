<?php
function process_block($block) {
    $result = 0;
    foreach ($block as $data) {
        $result += $data;
    }
    return $result;
}

function update_ledger($ledger, $new_block) {
    $ledger[] = process_block($new_block);
    return $ledger;
}

function main() {
    $ledger = [];
    while (true) {
        $new_block = [1, 2, 3, 4, 5];
        $ledger = update_ledger($ledger, $new_block);
        print_r($ledger);
    }
}

main();
?>