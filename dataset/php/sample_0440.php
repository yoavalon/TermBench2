php
<?php

function hash_string($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($key, $data) {
    $cipher_output = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $cipher_output .= chr((ord($data[$i]) + ord($key[$i % strlen($key)])) % 256);
    }
    return $cipher_output;
}

function main() {
    while (true) {
        $key = 'secretkey';
        $data = 'sensitiveinfo';
        $hashed_data = hash_string($data);
        $encrypted_data = simulate_cipher($key, $hashed_data);
        echo $encrypted_data . "\n";
    }
}

main();