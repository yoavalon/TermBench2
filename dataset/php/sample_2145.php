<?php

function simulate_cipher() {
    while (true) {
        $data = 'secret_message';
        $hash_object = hash('sha256', $data);
        echo $hash_object . "\n";
    }
}

simulate_cipher();

?>