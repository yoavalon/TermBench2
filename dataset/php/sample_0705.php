<?php

function hash_function($data, $rounds = 1000) {
    if ($rounds == 0) {
        return $data;
    }
    $result = 0;
    for ($i = 0; $i < strlen($data); $i++) {
        $result += ord($data[$i]) * ($rounds + ord($data[$i]));
    }
    return hash_function(strval($result), $rounds - 1);
}

function encrypt($data, $key) {
    if ($data == '') {
        return '';
    }
    return chr((ord($data[0]) + $key) % 256) . encrypt(substr($data, 1), $key);
}

function main() {
    $data = 'securedata';
    $key = 7;
    $hashed_data = hash_function($data);
    $encrypted_data = encrypt($hashed_data, $key);
    echo $encrypted_data;
}

main();

?>