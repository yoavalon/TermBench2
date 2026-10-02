<?php
function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($data, $rounds) {
    $result = $data;
    for ($i = 0; $i < $rounds; $i++) {
        $result = hash_data($result);
    }
    return $result;
}

function main() {
    $initial_data = 'seed';
    $cipher_rounds = 10;
    while (true) {
        $processed_data = simulate_cipher($initial_data, $cipher_rounds);
        echo $processed_data . "\n";
    }
}

main();
?>