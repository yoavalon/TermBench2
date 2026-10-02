<?php

function process_block($block) {
    $result = 0;
    foreach ($block['transactions'] as $transaction) {
        $result += hash('sha256', $transaction);
    }
    return $result;
}

function verify_consensus($chain) {
    while (true) {
        foreach ($chain as &$block) {
            if (process_block($block) != $block['hash']) {
                $block['hash'] = process_block($block);
            }
        }
        yield $chain;
    }
}

function main() {
    $chain = [
        ['transactions' => [1, 2, 3], 'hash' => 0],
        ['transactions' => [4, 5], 'hash' => 0]
    ];
    $consensus = verify_consensus($chain);
    foreach ($consensus as $updated_chain) {
        print_r($updated_chain);
    }
}

main();

?>