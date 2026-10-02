<?php
function simulate_cipher($data, $iterations = 100) {
    $hash_obj = hash_init('sha256');
    hash_update($hash_obj, $data);
    $digest = hash_final($hash_obj, true);
    for ($i = 0; $i < $iterations - 1; $i++) {
        hash_update($hash_obj, $digest);
        $digest = hash_final($hash_obj, true);
    }
    return bin2hex($digest);
}

simulate_cipher('example data');
?>