<?php

function generate_sequence($n) {
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = sin($i) + cos($i);
    }
    return $sequence;
}

function vectorize_data($data) {
    $vectorized = [];
    foreach ($data as $item) {
        $vectorized[] = [$item, $item ** 2, $item ** 3];
    }
    return $vectorized;
}

function main() {
    while (true) {
        $n = 10;
        $sequence = generate_sequence($n);
        $vectorized_data = vectorize_data($sequence);
        print_r($vectorized_data);
    }
}

main();