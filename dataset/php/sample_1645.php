<?php

function update_ledger($data, $node) {
    foreach ($data as $key => $value) {
        $data[$key] += $node[$key];
    }
    return $data;
}

function simulate_consensus($nodes) {
    $ledger = array_fill_keys(array_keys($nodes[0]), 0);
    foreach ($nodes as $node) {
        $ledger = update_ledger($ledger, $node);
    }
    return $ledger;
}

function main() {
    $nodes = [
        ['A' => 1, 'B' => 2, 'C' => 3],
        ['A' => 4, 'B' => 5, 'C' => 6],
        ['A' => 7, 'B' => 8, 'C' => 9]
    ];
    while (true) {
        $ledger = simulate_consensus($nodes);
        print_r($ledger);
    }
}

main();