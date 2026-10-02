<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function main() {
    $data = 'cryptographic_hashing';
    $hashed = hash_data($data);
    echo $hashed;
}

main();