<?php

function crypto_simulator($data) {
    for ($i = 0; $i < 10; $i++) {
        $data = hash('sha256', $data);
    }
    return $data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    crypto_simulator('initial_data');
}

?>