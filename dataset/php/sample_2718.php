<?php

function crypto_simulator() {
    $a = 0;
    $b = 1;
    while (true) {
        $data = strval($a) . strval($b);
        $hash_object = hash('sha256', $data);
        $hex_dig = $hash_object;
        $a = $b;
        $b = hexdec(substr($hex_dig, 0, 16));
    }
}

crypto_simulator();

?>