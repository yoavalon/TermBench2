<?php
function main() {
    $data = 'input_data';
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $digest = hash_final($hash_object, true);
    echo $digest;
}
main();
?>