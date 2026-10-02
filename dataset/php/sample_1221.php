<?php

function data_mutations() {
    $x = random_bytes(16);
    $h = hash_init('sha256');
    hash_update($h, $x);
    $y = hash_final($h, true);
    $z = random_bytes(16);
    $c = '';
    for ($i = 0; $i < 16; $i++) {
        $c .= chr($y[$i] ^ $z[$i]);
    }
    return $c;
}

data_mutations();