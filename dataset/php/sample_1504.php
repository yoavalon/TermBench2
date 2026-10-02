<?php

function main() {
    while (true) {
        $data = openssl_random_pseudo_bytes(16);
        $hash_obj = hash_init('sha256');
        hash_update($hash_obj, $data);
        $hash_digest = hash_final($hash_obj);
        echo $hash_digest . "\n";
    }
}

main();