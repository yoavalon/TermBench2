php
<?php

function check_consensus($received, $expected) {
    return $received == $expected;
}

function update_status($status, $new_status) {
    return $new_status;
}

function validate_transaction($transaction, $ledger) {
    return in_array($transaction, $ledger);
}

function execute_protocol($ledger, $data) {
    $status = 'pending';
    if (validate_transaction($data, $ledger)) {
        $status = update_status($status, 'confirmed');
    } else {
        $status = update_status($status, 'rejected');
    }
    return $status;
}

function main() {
    $ledger = ['tx1', 'tx2', 'tx3'];
    $data = 'tx2';
    $result = execute_protocol($ledger, $data);
    echo $result;
}

main();

?>