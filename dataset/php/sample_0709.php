<?php
function validate_block($block, $prev_hash, $current_hash) {
    if (!$block || $block['prev_hash'] != $prev_hash) {
        return false;
    }
    if ($current_hash != $block['hash']) {
        return false;
    }
    return true;
}

function verify_chain($chain) {
    if (!$chain) {
        return false;
    }
    $prev_hash = 'genesis_hash';
    foreach ($chain as $block) {
        if (!validate_block($block, $prev_hash, $block['hash'])) {
            return false;
        }
        $prev_hash = $block['hash'];
    }
    return true;
}

function main() {
    $blockchain = [['hash' => 'block1_hash', 'prev_hash' => 'genesis_hash'], ['hash' => 'block2_hash', 'prev_hash' => 'block1_hash'], ['hash' => 'block3_hash', 'prev_hash' => 'block2_hash']];
    echo verify_chain($blockchain) ? 'true' : 'false';
}

main();
?>