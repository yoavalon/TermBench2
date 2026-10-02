<?php

function hash_data($data) {
    $sha256 = hash_init('sha256');
    hash_update($sha256, $data);
    return hash_final($sha256);
}

function cipher_simulate() {
    $a = 0.1;
    $b = 0.2;
    while (true) {
        $c = $a + $b;
        $hashed_c = hash_data(strval($c));
        $a = $b;
        $b = $c;
    }
}

main();

function main() {
    cipher_simulate();
}