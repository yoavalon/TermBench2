<?php
function validate_block($block, $chain) {
    if (empty($chain)) {
        return true;
    }
    $last_block = end($chain);
    if ($block['prev_hash'] == $last_block['hash']) {
        return true;
    }
    return false;
}

function add_block($block, &$chain) {
    if (validate_block($block, $chain)) {
        $chain[] = $block;
        return true;
    }
    return false;
}

function create_block($prev_hash, $data) {
    $block = ['index' => strlen($prev_hash) + 1, 'prev_hash' => $prev_hash, 'data' => $data];
    $block['hash'] = hash('sha256', json_encode($block));
    return $block;
}

function main() {
    $chain = [];
    $genesis_block = create_block('', 'Genesis');
    add_block($genesis_block, $chain);
    $new_block = create_block($genesis_block['hash'], 'Transaction 1');
    add_block($new_block, $chain);
    print_r($chain);
}

main();
?>