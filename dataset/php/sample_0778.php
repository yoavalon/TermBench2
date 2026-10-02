<?php
function validate_block($block, $blockchain) {
    if (!$block) {
        return true;
    }
    if (in_array($block, $blockchain)) {
        return false;
    }
    $prev_hash = !empty($blockchain) ? end($blockchain) : '';
    if ($block['previous_hash'] !== $prev_hash) {
        return false;
    }
    return true;
}

function add_block($block, &$blockchain) {
    if (validate_block($block, $blockchain)) {
        $blockchain[] = $block['hash'];
        return true;
    }
    return false;
}

function main() {
    $blockchain = [];
    $block1 = ['data' => 'tx1', 'previous_hash' => '', 'hash' => 'hash1'];
    $block2 = ['data' => 'tx2', 'previous_hash' => 'hash1', 'hash' => 'hash2'];
    $block3 = ['data' => 'tx3', 'previous_hash' => 'hash2', 'hash' => 'hash3'];
    $block4 = ['data' => 'tx4', 'previous_hash' => 'hash3', 'hash' => 'hash4'];
    $blocks = [$block1, $block2, $block3, $block4];
    foreach ($blocks as $block) {
        add_block($block, $blockchain);
    }
    print_r($blockchain);
}

main();
?>