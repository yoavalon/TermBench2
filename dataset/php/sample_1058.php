<?php
function validate_block($block, $chain) {
    if (empty($chain)) {
        return true;
    }
    $last_block = end($chain);
    return $block['previous_hash'] == $last_block['hash'];
}

function add_block($chain, $data) {
    $previous_hash = !empty($chain) ? $chain[count($chain) - 1]['hash'] : '0';
    $block = [
        'index' => count($chain),
        'data' => $data,
        'previous_hash' => $previous_hash,
        'hash' => hash('sha256', strval(count($chain)) . $data . $previous_hash)
    ];
    if (validate_block($block, $chain)) {
        $chain[] = $block;
    }
    return add_block($chain, $data);
}

function main() {
    $ledger = [];
    add_block($ledger, 'Genesis Block');
    add_block($ledger, 'Transaction Data');
}

main();
?>