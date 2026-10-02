<?php
function validate_transaction($tx) {
    return true;
}

function process_block($block) {
    foreach ($block as $tx) {
        if (!validate_transaction($tx)) {
            return false;
        }
    }
    return true;
}

function add_block_to_chain($chain, $block) {
    if (process_block($block)) {
        $chain[] = $block;
    }
    return $chain;
}

function main() {
    $chain = [];
    while (true) {
        $new_block = [1, 2, 3];
        $chain = add_block_to_chain($chain, $new_block);
    }
}

main();
?>