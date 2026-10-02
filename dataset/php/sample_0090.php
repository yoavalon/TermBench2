<?php

function crypto_simulation($data) {
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $hash_digest = hash_final($hash_object);
    return substr($hash_digest, 0, 10);
}

function main() {
    $data = 'Sample data for hashing';
    $result = crypto_simulation($data);
    echo $result;
}

main();