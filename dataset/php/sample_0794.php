<?php

function validate_blockchain($blockchain, $index) {
    if ($index >= count($blockchain)) {
        return true;
    }
    $previous_block = $index > 0 ? $blockchain[$index - 1] : '';
    if ($blockchain[$index] !== hash('sha256', $previous_block)) {
        return false;
    }
    return validate_blockchain($blockchain, $index + 1);
}

function append_block(&$blockchain, $new_block) {
    if (validate_blockchain($blockchain, 0)) {
        $blockchain[] = $new_block;
    }
}

function main() {
    $blockchain = ['genesis'];
    append_block($blockchain, 'block1');
    append_block($blockchain, 'block2');
    var_dump(validate_blockchain($blockchain, 0));
}

main();

?>