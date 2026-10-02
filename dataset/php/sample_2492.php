<?php

function generate_hash_sequence($seed, $length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $hash_object = hash('sha256', $seed);
        $sequence[] = $hash_object;
        $seed = $hash_object;
    }
    return $sequence;
}

generate_hash_sequence('start', 10);

?>