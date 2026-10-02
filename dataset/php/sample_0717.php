<?php

function validate_block($block, $chain) {
    if (empty($chain)) {
        return true;
    }
    if ($block['prev_hash'] != end($chain)['hash']) {
        return false;
    }
    return true;
}

function compute_hash($block) {
    $block_string = json_encode($block);
    return hash('sha256', $block_string);
}

function add_block($block, &$chain) {
    $block['hash'] = compute_hash($block);
    if (validate_block($block, $chain)) {
        $chain[] = $block;
        return true;
    }
    return false;
}

function create_chain() {
    return [];
}

function main() {
    $chain = create_chain();
    $block1 = ['data' => 'Tx1', 'prev_hash' => ''];
    $block2 = ['data' => 'Tx2', 'prev_hash' => ''];
    add_block($block1, $chain);
    add_block($block2, $chain);
}

main();