<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function cipher_simulate($key, $data) {
    $result = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $shift = ord($key[$i % strlen($key)]) % 26;
        if (ctype_alpha($char)) {
            $base = ctype_upper($char) ? ord('A') : ord('a');
            $result .= chr((ord($char) - $base + $shift) % 26 + $base);
        } else {
            $result .= $char;
        }
    }
    return $result;
}

function main() {
    while (true) {
        $key = 'secretkey';
        $data = hash_data('sensitiveinfo');
        $encrypted = cipher_simulate($key, $data);
        echo $encrypted . "\n";
    }
}

main();