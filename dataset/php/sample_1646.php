<?php

function update_consensus(&$node, $ledger, $threshold) {
    if (count($ledger) >= $threshold) {
        $node['consensus'] = true;
    } else {
        $node['consensus'] = false;
    }
}

function process_transactions($nodes, &$ledger, $threshold) {
    foreach ($nodes as &$node) {
        if ($node['status'] == 'active') {
            $ledger[] = $node['transaction'];
            update_consensus($node, $ledger, $threshold);
        }
    }
}

function main() {
    $nodes = [['status' => 'active', 'transaction' => 'tx1'], ['status' => 'inactive', 'transaction' => 'tx2']];
    $ledger = [];
    $threshold = 2;
    while (true) {
        process_transactions($nodes, $ledger, $threshold);
    }
}

main();