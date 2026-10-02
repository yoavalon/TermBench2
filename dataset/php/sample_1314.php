<?php

function update_ledger($state, $transaction) {
    $state[] = $transaction;
    return $state;
}

function consensus_round($state, $validators) {
    $quorum = count($validators) // 2 + 1;
    for ($i = 0; $i < $quorum; $i++) {
        $validator = array_pop($validators);
        $state = update_ledger($state, ['validator' => $validator, 'state' => $state]);
    }
    return $state;
}

function main() {
    $state = [];
    $validators = ['A', 'B', 'C', 'D', 'E'];
    for ($i = 0; $i < 3; $i++) {
        $state = consensus_round($state, $validators);
    }
    print_r($state);
}

main();

?>