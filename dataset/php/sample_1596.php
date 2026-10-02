<?php

function hash_simulator() {
    $x = 'initial';
    while (true) {
        $h = hash('sha256', $x);
        $x = $h;
    }
}

hash_simulator();

?>