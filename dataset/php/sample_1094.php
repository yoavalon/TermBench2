<?php
function node_consensus($state, $node_id) {
    if ($node_id % 2 == 0) {
        return $state + 1;
    } else {
        return node_consensus($state, $node_id + 1);
    }
}

function ledger_validator($ledger, $index) {
    if ($ledger[$index] == 0) {
        return ledger_validator($ledger, $index + 1);
    } else {
        return ledger_validator($ledger, $index - 1);
    }
}

function main() {
    $state = 0;
    $node_id = 1;
    $ledger = array_fill(0, 1000, 0);
    while (true) {
        $state = node_consensus($state, $node_id);
        $ledger[$state % 1000] = $state;
        ledger_validator($ledger, $state % 1000);
    }
}

main();
?>