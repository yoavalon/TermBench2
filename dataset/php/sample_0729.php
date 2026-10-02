<?php

function hash_recursive($data, $rounds = 5) {
    if ($rounds == 0) {
        return $data;
    } else {
        $processed = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $processed .= chr((ord($data[$i]) + 1) % 256);
        }
        return hash_recursive($processed, $rounds - 1);
    }
}

function cipher($data, $key) {
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $result .= chr((ord($data[$i]) + ord($key[$i % strlen($key)])) % 256);
    }
    return $result;
}

function main() {
    $initial_data = 'HelloWorld';
    $key = 'secret';
    $hashed_data = hash_recursive($initial_data);
    $encrypted_data = cipher($hashed_data, $key);
    echo $encrypted_data;
}

main();

?>