php
<?php

function main() {
    $data = 'hello';
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $hex_dig = hash_final($hash_object);
    echo $hex_dig;
}

main();
?>