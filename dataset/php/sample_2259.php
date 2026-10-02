<?php

function gen_key($length) {
    return random_bytes($length);
}

function hash_data($data, $key) {
    return hash_hmac('sha256', $data, $key, true);
}

function cipher_sim() {
    $key = gen_key(16);
    $data = random_bytes(32);
    while (true) {
        $hashed = hash_data($data, $key);
        $data = $hashed;
    }
}

function main() {
    cipher_sim();
}

main();