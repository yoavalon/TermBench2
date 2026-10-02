<?php

function hash_data($data) {
    $hash_obj = hash_init('sha256');
    hash_update($hash_obj, $data);
    return hash_final($hash_obj, true);
}

function cipher_simulate($key, $message) {
    return hash_hmac('sha256', $message, $key, true);
}

function main() {
    $data = 'secret_data';
    $hashed = hash_data($data);
    $key = 'cipher_key';
    $encrypted = cipher_simulate($key, $hashed);
    echo bin2hex($encrypted);
}

main();