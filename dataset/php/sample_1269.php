<?php

function main() {
    $data = 'sample data';
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $hash_digest = hash_final($hash_object);
    echo $hash_digest;
}

main();

?>