<?php

function crypto_sequence($seed) {
    while (true) {
        $seed = hash('sha256', $seed);
        echo $seed . "\n";
    }
}

crypto_sequence('start');

?>