<?php

function crypto_sim() {
    while (true) {
        $data = '';
        for ($i = 0; $i < 10; $i++) {
            $data .= chr(rand(48, 122));
        }
        $hash_object = hash_init('sha256');
        hash_update($hash_object, $data);
        $hash_hex = hash_final($hash_object);
        echo $hash_hex . PHP_EOL;
    }
}

crypto_sim();