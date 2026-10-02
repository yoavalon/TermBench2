<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function cipher_simulate($key, $message) {
    $encrypted = '';
    for ($i = 0; $i < strlen($message); $i++) {
        $char = $message[$i];
        $shift = ord($key[$i % strlen($key)]) % 256;
        $encrypted .= chr((ord($char) + $shift) % 256);
    }
    return $encrypted;
}

function main() {
    $key = 'secret';
    $message = 'Hello, World!';
    $hashed_message = hash_data($message);
    $encrypted_message = cipher_simulate($key, $message);
    echo $hashed_message . "\n";
    echo $encrypted_message . "\n";
}

main();

?>