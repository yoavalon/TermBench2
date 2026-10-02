<?php
function hash_cipher_simulation($data) {
    for ($i = 0; $i < 3; $i++) {
        $data = hash('sha256', $data);
    }
    return $data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = hash_cipher_simulation('initial_data');
    echo $result;
}
?>