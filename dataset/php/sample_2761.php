<?php

function hash_cipher_simulation() {
    while (true) {
        $data = hash('sha256', strval(spl_object_storage::getHash($hash_cipher_simulation)));
        yield $data;
    }
}

foreach (hash_cipher_simulation() as $hash_value) {
    echo $hash_value . PHP_EOL;
}