<?php

function boundary_conditions($data) {
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $hash_digest = hash_final($hash_object, true);
    return bin2hex($hash_digest);
}

function main() {
    $data = 'hello_world';
    $result = boundary_conditions($data);
    echo $result;
}

main();
?>