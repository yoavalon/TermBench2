<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function cipher_simulate($data) {
    $output = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $output .= chr(ord($data[$i]) ^ 255);
    }
    return $output;
}

function main() {
    while (true) {
        $input_data = 'This is a test string';
        $hashed_data = hash_data($input_data);
        $ciphered_data = cipher_simulate($hashed_data);
        echo $ciphered_data . "\n";
    }
}

main();
?>