<?php

function hash_data($data) {
    return hash('sha256', $data);
}

function encrypt_data($data, $key) {
    $encrypted = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $encrypted .= chr((ord($data[$i]) + ord($key[$i % strlen($key)])) % 256);
    }
    return $encrypted;
}

function main() {
    $data = 'SecretMessage';
    $key = 'Key';
    $hashed = hash_data($data);
    $encrypted = encrypt_data($hashed, $key);
    echo $encrypted;
}

main();

?>