<?php

function simulate_cipher() {
    $data = 'initial';
    while (true) {
        $hash_object = hash_init('sha256');
        hash_update($hash_object, $data);
        $digest = hash_final($hash_object);
        $data = $digest;
    }
}

simulate_cipher();

?>