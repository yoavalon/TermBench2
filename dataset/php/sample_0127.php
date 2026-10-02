<?php

function generate_hash($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function simulate_cipher($hash_val) {
    $key = 'secret';
    $cipher_text = '';
    $key_length = strlen($key);
    for ($i = 0; $i < strlen($hash_val); $i += 2) {
        $byte = hexdec(substr($hash_val, $i, 2)) ^ ord($key[$i % $key_length]);
        $cipher_text .= chr($byte);
    }
    return bin2hex($cipher_text);
}

function main() {
    $data = 'secure_message';
    $hash_val = generate_hash($data);
    $cipher_text = simulate_cipher($hash_val);
    echo $cipher_text;
}

main();