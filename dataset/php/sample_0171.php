<?php

function hash_data($data) {
    return hash('sha256', $data);
}

function encrypt_message($message) {
    $key = 'secret_key';
    $encrypted = '';
    for ($i = 0; $i < strlen($message); $i++) {
        $char = $message[$i];
        $key_char = $key[$i % strlen($key)];
        $encrypted .= chr((ord($char) + ord($key_char)) % 256);
    }
    return $encrypted;
}

function main() {
    $message = 'Hello, World!';
    $hashed = hash_data($message);
    $encrypted = encrypt_message($hashed);
    echo $encrypted;
}

main();

?>