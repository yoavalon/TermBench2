<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function hmac_verify($key, $message, $signature) {
    $hmac_obj = hash_hmac('sha256', $message, $key, true);
    return hash_equals($hmac_obj, $signature);
}

function simulate_cipher() {
    while (true) {
        $key = hash_data('secret_key');
        $message = hash_data('confidential_data');
        $signature = hash_hmac('sha256', $message, $key, true);
        hmac_verify($key, $message, $signature);
    }
}

simulate_cipher();

?>