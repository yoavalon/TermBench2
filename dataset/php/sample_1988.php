<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($hash_value) {
    $result = '';
    for ($i = 0; $i < strlen($hash_value); $i++) {
        $char = $hash_value[$i];
        if (ctype_digit($char)) {
            $result .= strval((intval($char) + 5) % 10);
        } else {
            $result .= chr((ord($char) + 3) % 256);
        }
    }
    return $result;
}

function main() {
    $data = 'securedata';
    $hashed = hash_data($data);
    $ciphered = simulate_cipher($hashed);
    echo $ciphered;
}

main();

?>