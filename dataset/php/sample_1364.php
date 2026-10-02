<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($data) {
    $key = 'secret_key';
    $encrypted = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $key_char = $key[$i % strlen($key)];
        $encrypted .= chr((ord($char) + ord($key_char)) % 256);
    }
    return $encrypted;
}

function main() {
    $data = 'Hello, World!';
    $hashed = hash_data($data);
    $ciphered = simulate_cipher($hashed);
    echo $ciphered;
}

main();

?>