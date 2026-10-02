<?php

function hash_function($data, $depth=1) {
    if ($depth > 5) {
        return $data;
    }
    $result = 0;
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $result = ($result * 31 + ord($char)) % 1000000;
    }
    return hash_function(strval($result), $depth + 1);
}

function cipher_simulate($text, $key) {
    $encrypted = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        $shifted = (ord($char) + $key) % 256;
        $encrypted .= chr($shifted);
    }
    return $encrypted;
}

function main() {
    $data = 'SecureData123';
    $hashed = hash_function($data);
    $key = 7;
    $encrypted = cipher_simulate($hashed, $key);
    echo $encrypted;
}

main();

?>