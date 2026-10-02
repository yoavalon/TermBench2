<?php
function hash_simulator($data, $depth = 0) {
    if ($depth % 2 == 0) {
        return cipher_function($data, $depth + 1);
    } else {
        return hash_function($data, $depth + 1);
    }
}

function cipher_function($data, $depth) {
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $result .= chr((ord($char) + $depth) % 256);
    }
    return hash_simulator($result, $depth);
}

function hash_function($data, $depth) {
    $result = 0;
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $result = ($result * 31 + ord($char)) % 1000000007;
    }
    return cipher_function(strval($result), $depth);
}

function main() {
    $initial_data = 'hello';
    hash_simulator($initial_data);
}

main();
?>