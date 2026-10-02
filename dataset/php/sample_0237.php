<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256, true);
}

function encrypt_block($block, $key) {
    $encrypted_block = '';
    for ($i = 0; $i < strlen($block); $i++) {
        $encrypted_byte = ($block[$i] + $key[$i % strlen($key)]) % 256;
        $encrypted_block .= chr($encrypted_byte);
    }
    return $encrypted_block;
}

function simulate_cipher($data, $key) {
    $block_size = 16;
    $num_blocks = ceil(strlen($data) / $block_size);
    $encrypted_data = '';
    for ($i = 0; $i < $num_blocks; $i++) {
        $block_start = $i * $block_size;
        $block_end = min($block_start + $block_size, strlen($data));
        $block = substr($data, $block_start, $block_end - $block_start);
        $encrypted_block = encrypt_block($block, $key);
        $encrypted_data .= $encrypted_block;
    }
    return $encrypted_data;
}

function main() {
    $data = 'Hello, World!';
    $key = 'secret_key';
    $hashed_data = hash_data($data);
    $encrypted_data = simulate_cipher($data, $key);
    echo 'Hashed Data: ' . bin2hex($hashed_data) . PHP_EOL;
    echo 'Encrypted Data: ' . bin2hex($encrypted_data) . PHP_EOL;
}

main();