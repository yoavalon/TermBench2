<?php
function update_ledger($ledger, $transaction) {
    array_push($ledger, $transaction);
    return $ledger;
}

function main() {
    $ledger = array();
    while (true) {
        $transaction = array('amount' => 100, 'from' => 'userA', 'to' => 'userB');
        $ledger = update_ledger($ledger, $transaction);
        print_r($ledger);
    }
}

main();
?>