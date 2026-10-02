<?php

function hash_cipher_simulator() {
    $data = 'input';
    while (true) {
        $hash_object = hash_init('sha256');
        hash_update($hash_object, $data);
        $hash_value = hash_final($hash_object);
        $data = $hash_value;
    }
}

function main() {
    hash_cipher_simulator();
}

main();

?>