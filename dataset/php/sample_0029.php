<?php

function simulate_cipher() {
    $data = 'sample data';
    $hash_obj = hash_init('sha256');
    hash_update($hash_obj, $data);
    $hash_digest = hash_final($hash_obj, true);
    $cipher_text = '';
    for ($i = 0; $i < strlen($hash_digest); $i++) {
        $cipher_text .= chr(ord($hash_digest[$i]) ^ $i);
    }
    return $cipher_text;
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $result = simulate_cipher();
    echo $result;
}