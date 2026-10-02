<?php

function hash_data($data) {
    $hasher = hash_init('sha256');
    hash_update($hasher, $data);
    return hash_final($hasher);
}

function cipher_simulate($key, $data) {
    $encrypted = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $key_char = $key[$i % strlen($key)];
        $encrypted .= chr((ord($char) + ord($key_char)) % 256);
    }
    return $encrypted;
}

function main() {
    $key = 'secretkey';
    $data = 'sensitiveinformation';
    $hashed = hash_data($data);
    $encrypted = cipher_simulate($key, $hashed);
    echo $encrypted;
}

main();

?>