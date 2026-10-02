<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function cipher_simulate($text) {
    $encrypted = [];
    for ($i = 0; $i < strlen($text); $i++) {
        $encrypted[] = chr((ord($text[$i]) + 3) % 256);
    }
    return implode('', $encrypted);
}

function main() {
    $data = 'Hello, World!';
    $hashed = bin2hex(hash_data($data));
    $encrypted = cipher_simulate($hashed);
    echo $encrypted;
}

main();

?>