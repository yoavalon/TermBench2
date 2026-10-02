<?php
function process_data($data) {
    $hash_object = hash_init('sha256');
    hash_update($hash_object, $data);
    $hash_digest = hash_final($hash_object, true);
    return substr($hash_digest, 0, 16);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = 'Sample data for cryptographic hashing';
    $result = process_data($data);
    print($result);
}
?>