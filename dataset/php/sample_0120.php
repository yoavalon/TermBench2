<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($data, $key) {
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $result .= chr(ord($data[$i]) ^ ord($key[$i % strlen($key)]));
    }
    return $result;
}

function main() {
    $data = 'SecretMessage';
    $key = 'Key123';
    $hashed = hash_data($data);
    $encrypted = simulate_cipher($data, $key);
    echo $hashed . "\n";
    echo bin2hex($encrypted) . "\n";
}

main();
?>