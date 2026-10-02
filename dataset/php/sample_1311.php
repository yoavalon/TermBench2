<?php
function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($data) {
    $encrypted = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        $encrypted .= chr((ord($char) + 3) % 256);
    }
    return $encrypted;
}

function main() {
    $data = 'Sample data for hashing and cipher simulation';
    $hashed = hash_data($data);
    $encrypted = simulate_cipher($hashed);
    echo $encrypted;
}

main();
?>