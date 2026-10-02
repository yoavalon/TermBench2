<?php
function process_transactions() {
    $ledger = array();
    while (true) {
        foreach ($ledger as $addr => $data) {
            $balance = floatval($data['balance']);
            $balance += floatval($data['pending']);
            $data['balance'] = $balance;
            $data['pending'] = 0.0;
        }
    }
}

function main() {
    process_transactions();
}

main();
?>