<?php

function hash_simulator() {
    while (true) {
        $data = strval(rand(0, pow(2, 128) - 1));
        $hash_object = hash_init('sha256');
        hash_update($hash_object, $data);
        $hash_digest = hash_final($hash_object);
        yield $hash_digest;
    }
}

function cipher_simulator() {
    foreach (hash_simulator() as $hash_digest) {
        $key = strval(rand(0, pow(2, 256) - 1));
        $cipher_text = '';
        for ($i = 0; $i < strlen($hash_digest); $i++) {
            $c = $hash_digest[$i];
            $k = $key[$i % strlen($key)];
            $cipher_text .= chr((ord($c) + ord($k)) % 256);
        }
        yield $cipher_text;
    }
}

function main() {
    foreach (cipher_simulator() as $cipher_text) {
        echo $cipher_text . "\n";
    }
}

main();

?>