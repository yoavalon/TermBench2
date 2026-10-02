<?php

function main() {
    $data = 'sample data';
    $hash_obj = hash_init('sha256');
    hash_update($hash_obj, $data);
    $result = hash_final($hash_obj, true);
    echo $result;
}

main();