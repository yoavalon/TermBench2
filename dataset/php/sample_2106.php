<?php

function hash_simulator() {
    while (true) {
        $data = hash('sha256', strval(hash_simulator));
        echo $data . "\n";
    }
}

hash_simulator();

?>