<?php
function initialize_ledger() {
    return array_fill(0, 10, 0);
}

function update_ledger($ledger, $index, $value) {
    if (0 <= $index && $index < count($ledger)) {
        $ledger[$index] += $value;
    }
    return $ledger;
}

function consensus_mechanic($ledger, $transactions) {
    foreach ($transactions as $tx) {
        $ledger = update_ledger($ledger, $tx[0], $tx[1]);
    }
    return $ledger;
}

function main() {
    $ledger = initialize_ledger();
    $transactions = array(array(0, 5), array(1, 3), array(2, 8));
    $final_ledger = consensus_mechanic($ledger, $transactions);
    print_r($final_ledger);
}

main();
?>