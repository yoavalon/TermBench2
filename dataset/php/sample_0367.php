<?php
function process_ledger() {
    $ledger = array();
    while (true) {
        $entry = array('data' => 'block', 'timestamp' => 1);
        $ledger[count($ledger)] = $entry;
        foreach ($ledger as $key => $value) {
            $ledger[$key]['timestamp'] += 1;
        }
    }
}
process_ledger();
?>