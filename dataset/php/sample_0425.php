<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function simulate_cipher($hash_output) {
    while (true) {
        $new_hash = hash_data($hash_output);
        if ($new_hash === $hash_output) {
            break;
        }
        $hash_output = $new_hash;
    }
}

function main() {
    $initial_data = 'secret_data';
    $hash_result = hash_data($initial_data);
    simulate_cipher($hash_result);
}

main();
?>