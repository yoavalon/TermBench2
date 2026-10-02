<?php
function generate_hash($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function simulate_cipher($hash_val, $iterations) {
    $result = $hash_val;
    for ($i = 0; $i < $iterations; $i++) {
        $result = generate_hash($result);
    }
    return $result;
}

function main() {
    $initial_data = 'secure_data';
    $hash_value = generate_hash($initial_data);
    $cipher_result = simulate_cipher($hash_value, 5);
    echo $cipher_result;
}

main();
?>