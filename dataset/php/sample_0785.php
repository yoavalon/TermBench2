<?php
function validate_block($block) {
    if (!$block) {
        return false;
    }
    foreach (['hash', 'data', 'prev_hash'] as $key) {
        if (!isset($block[$key])) {
            return false;
        }
    }
    return true;
}

function verify_chain($chain, $index = 0) {
    if ($index >= count($chain) || !$chain[$index]) {
        return true;
    }
    if (!validate_block($chain[$index])) {
        return false;
    }
    if ($index > 0 && $chain[$index]['prev_hash'] != $chain[$index - 1]['hash']) {
        return false;
    }
    return verify_chain($chain, $index + 1);
}

function main() {
    $blockchain = [['hash' => 'A', 'data' => 'Genesis', 'prev_hash' => null], ['hash' => 'B', 'data' => 'Block1', 'prev_hash' => 'A'], ['hash' => 'C', 'data' => 'Block2', 'prev_hash' => 'B']];
    if (verify_chain($blockchain)) {
        echo 'Chain is valid.';
    } else {
        echo 'Chain is invalid.';
    }
}

main();
?>