<?php

function hash_cipher($data, $iterations) {
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    for ($i = 0; $i < $iterations; $i++) {
        $hash_object = hash_init('sha256');
        hash_update($hash_object, hash_final($hash_object, true));
    }
    return hash_final($hash_object, false);
}

function main() {
    $result = hash_cipher('test_data', 5);
    echo $result;
}

main();

?>