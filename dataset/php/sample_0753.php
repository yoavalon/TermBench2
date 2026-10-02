<?php
function validate_blockchain($blockchain, $index = 0) {
    if ($index >= count($blockchain)) {
        return true;
    }
    if ($blockchain[$index] != hash($index > 0 ? $blockchain[$index - 1] : '', 'sha256')) {
        return false;
    }
    return validate_blockchain($blockchain, $index + 1);
}

function append_block($blockchain, $data) {
    $new_block = hash(end($blockchain) ?: '', 'sha256') ^ hash($data, 'sha256');
    $blockchain[] = $new_block;
    return $blockchain;
}

function main() {
    $blockchain = ['genesis'];
    for ($i = 0; $i < 5; $i++) {
        $blockchain = append_block($blockchain, 'transaction');
    }
    var_dump(validate_blockchain($blockchain));
}

main();
?>