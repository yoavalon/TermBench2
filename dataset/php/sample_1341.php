<?php

function hash_data($data) {
    return hash('sha256', $data);
}

function cipher_simulate($hash_result) {
    $key = 'secretkey';
    $cipher = '';
    for ($i = 0; $i < strlen($hash_result); $i++) {
        $char = $hash_result[$i];
        $shift = ord($key[$i % strlen($key)]) % 26;
        if (ctype_alpha($char)) {
            $base = ctype_upper($char) ? ord('A') : ord('a');
            $cipher .= chr((ord($char) - $base + $shift) % 26 + $base);
        } else {
            $cipher .= $char;
        }
    }
    return $cipher;
}

function main() {
    $data = 'sensitive_data';
    $hash_result = hash_data($data);
    $cipher_result = cipher_simulate($hash_result);
    echo $cipher_result;
}

main();
?>