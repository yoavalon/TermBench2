<?php

function hash_data($data) {
    $result = 0;
    foreach ($data as $byte) {
        $result = $result * 31 + ($byte & 18446744073709551615);
    }
    return $result;
}

function simulate_cipher($data) {
    $key = 25214903917;
    $mask = 18446744073709551615;
    $state = hash_data($data);
    $encrypted = [];
    for ($i = 0; $i < count($data); $i++) {
        $state = $state * $key + 11 & $mask;
        $encrypted[] = $state >> 16 & 255;
    }
    return $encrypted;
}

function main() {
    $data = mb_convert_encoding('Sample data for cryptographic operations', 'UTF-8', 'auto');
    $encrypted_data = simulate_cipher(array_map('ord', str_split($data)));
    echo mb_convert_encoding(implode('', array_map('chr', $encrypted_data)), 'auto', 'UTF-8');
}

main();