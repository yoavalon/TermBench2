<?php

function hash_function($data) {
    return hash('sha256', $data);
}

function consensus_mechanism(&$blockchain, $new_block) {
    $block_hash = hash_function($new_block);
    $blockchain[] = $block_hash;
    if (count($blockchain) >= 10) {
        return true;
    }
    return false;
}

function main() {
    $blockchain = [];
    for ($i = 0; $i < 15; $i++) {
        $new_block = 'Block_' . $i;
        if (consensus_mechanism($blockchain, $new_block)) {
            break;
        }
    }
}

main();

?>