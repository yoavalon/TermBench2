<?php
function hash_function($data, $rounds) {
    if ($rounds == 0) {
        return $data;
    } else {
        $result = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $result .= chr((ord($data[$i]) + $rounds) % 256);
        }
        return hash_function($result, $rounds - 1);
    }
}

function cipher_encrypt($data, $rounds) {
    if ($rounds == 0) {
        return $data;
    } else {
        $encrypted = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $encrypted .= chr(ord($data[$i]) * $rounds % 256);
        }
        return cipher_encrypt($encrypted, $rounds - 1);
    }
}

function main() {
    $initial_data = 'Hello';
    $hashed_data = hash_function($initial_data, 3);
    $encrypted_data = cipher_encrypt($hashed_data, 2);
    echo $encrypted_data;
}

main();
?>