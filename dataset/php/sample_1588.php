<?php

function hash_simulator() {
    $a = 'abc';
    while (true) {
        $h = hash('sha256', $a);
        $a = $h;
    }
}

hash_simulator();

?>