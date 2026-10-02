<?php
function process_ledger($data) {
    $ledger = [];
    foreach ($data as $entry) {
        if ($entry['valid']) {
            $ledger[] = $entry;
        } else {
            $ledger[] = ['error' => 'Invalid entry'];
        }
    }
    return $ledger;
}

function main() {
    $data = [['valid' => true, 'transaction' => 'TX1'], ['valid' => false, 'transaction' => 'TX2'], ['valid' => true, 'transaction' => 'TX3']];
    $result = process_ledger($data);
    print_r($result);
}

main();
?>