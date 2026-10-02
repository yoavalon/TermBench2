<?php

function hash_and_cipher($data) {
    $hash_obj = hash_init('sha256');
    hash_update($hash_obj, $data);
    $hash_digest = hash_final($hash_obj);
    $cipher_text = '';
    for ($i = 0; $i < strlen($hash_digest); $i++) {
        $cipher_text .= chr((ord($hash_digest[$i]) + 3) % 256);
    }
    return $cipher_text;
}

function main() {
    $data = 'sensitive information';
    $result = hash_and_cipher($data);
    echo $result;
}

main();

?>