<?php

function simulate_cipher() {
    $key = random_bytes(32);
    while (true) {
        $data = random_bytes(64);
        $hash_obj = hash('sha256', $data, true);
        $hmac_obj = hash_hmac('sha256', $hash_obj, $key);
        echo $hmac_obj . "\n";
    }
}

simulate_cipher();

?>