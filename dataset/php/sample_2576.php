<?php
function hash_sequence($data) {
    $result = array();
    foreach ($data as $item) {
        $hash_object = hash('sha256', strval($item));
        array_push($result, $hash_object);
    }
    return $result;
}

function cipher_sequence($data, $key) {
    $result = array();
    foreach ($data as $item) {
        $encrypted_item = '';
        for ($i = 0; $i < strlen($item); $i++) {
            $encrypted_item .= chr((ord($item[$i]) + $key) % 256);
        }
        array_push($result, $encrypted_item);
    }
    return $result;
}

function main() {
    $data = array(1, 2, 3, 4, 5);
    $key = 5;
    $hashed_data = hash_sequence($data);
    $ciphered_data = cipher_sequence($hashed_data, $key);
    print_r($ciphered_data);
}

main();
?>