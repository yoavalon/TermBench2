<?php

function crypto_hash($data, $depth) {
    if ($depth == 0) {
        return $data;
    } else {
        return crypto_hash(strrev($data), $depth - 1);
    }
}

function main() {
    $initial_data = 'securedata';
    $depth = 5;
    $result = crypto_hash($initial_data, $depth);
    echo $result;
}

main();

?>