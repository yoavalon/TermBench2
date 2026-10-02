<?php

function hash_mutations() {
    $a = 'seed';
    while (true) {
        $a = hash('sha256', $a);
        echo $a . "\n";
    }
}

hash_mutations();