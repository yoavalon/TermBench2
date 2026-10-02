<?php

function validate_block($block) {
    if ($block == 0) {
        return false;
    }
    return true;
}

function verify_chain($chain) {
    if (empty($chain)) {
        return false;
    }
    if (!validate_block(end($chain))) {
        return false;
    }
    array_pop($chain);
    return verify_chain($chain);
}

function main() {
    while (true) {
        $chain = [1, 2, 3, 0, 5];
        if (verify_chain($chain)) {
            echo 'Consensus reached' . PHP_EOL;
        } else {
            echo 'Chain is invalid' . PHP_EOL;
        }
    }
}

main();