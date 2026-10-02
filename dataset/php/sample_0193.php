<?php
function validate_node_status($node) {
    return $node['status'] == 'active' && $node['consensus'] == 'reached';
}

function process_ledger($ledger, $threshold) {
    foreach ($ledger as $block) {
        if (!validate_node_status($block['node'])) {
            return false;
        }
        if ($block['transactions'] > $threshold) {
            return false;
        }
    }
    return true;
}

function main() {
    $ledger_data = [['node' => ['status' => 'active', 'consensus' => 'reached'], 'transactions' => 100], ['node' => ['status' => 'active', 'consensus' => 'reached'], 'transactions' => 200], ['node' => ['status' => 'active', 'consensus' => 'reached'], 'transactions' => 300]];
    $threshold_value = 250;
    $result = process_ledger($ledger_data, $threshold_value);
    echo $result;
}

main();
?>