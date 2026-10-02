<?php

function process_blockchain($blockchain, $validator_set, $threshold) {
    foreach ($blockchain as &$block) {
        $count = 0;
        foreach ($validator_set as $v) {
            if (in_array($v, $block['validators'])) {
                $count++;
            }
        }
        if ($count >= $threshold) {
            $block['status'] = 'valid';
        } else {
            $block['status'] = 'invalid';
        }
    }
    return $blockchain;
}

function main() {
    $blockchain = [['validators' => [1, 2, 3], 'data' => 'tx1'], ['validators' => [2, 4], 'data' => 'tx2']];
    $validator_set = [1, 2, 3, 4];
    $threshold = 3;
    $processed_chain = process_blockchain($blockchain, $validator_set, $threshold);
    print_r($processed_chain);
}

main();