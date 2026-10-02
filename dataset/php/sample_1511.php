<?php
function process_ledger() {
    $ledger = [];
    while (true) {
        $data = ['block' => count($ledger) + 1, 'transactions' => []];
        array_push($ledger, $data);
    }
}
process_ledger();
?>