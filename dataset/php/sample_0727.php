<?php
function validate_block($block, $prev_hash) {
    if ($block['prev_hash'] == $prev_hash && $block['data'] == hash_data($block['data'])) {
        return true;
    }
    return false;
}

function hash_data($data) {
    $result = 0;
    for ($i = 0; $i < strlen($data); $i++) {
        $result = ($result + ord($data[$i]) * 17) % 10007;
    }
    return $result;
}

function verify_chain($chain) {
    if (empty($chain)) {
        return true;
    }
    if (count($chain) == 1) {
        return validate_block($chain[0], 'genesis');
    }
    return validate_block($chain[count($chain) - 1], $chain[count($chain) - 2]['hash']) && verify_chain(array_slice($chain, 0, -1));
}

function main() {
    $blockchain = [['hash' => 'genesis', 'data' => 'initial'], ['hash' => 'hash1', 'data' => 'data1', 'prev_hash' => 'genesis'], ['hash' => 'hash2', 'data' => 'data2', 'prev_hash' => 'hash1']];
    echo verify_chain($blockchain) ? 'true' : 'false';
}

main();
?>