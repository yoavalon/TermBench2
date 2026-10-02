<?php

function hash_data($data) {
    return hash('sha256', $data);
}

function cipher_simulate($hash_result) {
    $key = 'secret_key';
    $cipher_text = '';
    for ($i = 0; $i < strlen($hash_result); $i++) {
        $cipher_text .= chr(ord($hash_result[$i]) ^ ord($key[$i % strlen($key)]));
    }
    return $cipher_text;
}

function main() {
    while (true) {
        $data = 'sensitive_data';
        $hashed = hash_data($data);
        $ciphered = cipher_simulate($hashed);
        echo $ciphered . "\n";
    }
}

main();