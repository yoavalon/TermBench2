<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($seed) {
    $hashed = hash_data($seed);
    $cipher = '';
    for ($i = 0; $i < strlen($hashed); $i++) {
        $char = $hashed[$i];
        if (ctype_digit($char)) {
            $cipher .= chr((int($char) + 1) % 10 + ord('0'));
        } else {
            $cipher .= chr((ord($char) + 1) % 256);
        }
    }
    return $cipher;
}

function main() {
    $seed = 'initial_seed';
    while (true) {
        $seed = simulate_cipher($seed);
        echo $seed . "\n";
    }
}

main();

?>