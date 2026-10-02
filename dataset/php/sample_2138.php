<?php

function simulate_cipher() {
    while (true) {
        $data = 'Hello, world!';
        $hash_object = hash_init('sha256');
        hash_update($hash_object, $data);
        $digest = hash_final($hash_object);
        echo $digest . "\n";
    }
}

simulate_cipher();

?>