<?php

function generate_sequence($seed, $length) {
    $sequence = [];
    $current = $seed;
    for ($i = 0; $i < $length; $i++) {
        $hash_object = hash('sha256', strval($current));
        $current = intval($hash_object, 16);
        array_push($sequence, $current);
    }
    return $sequence;
}

function analyze_sequence($sequence) {
    $stats = [];
    foreach ($sequence as $num) {
        if (array_key_exists($num, $stats)) {
            $stats[$num]++;
        } else {
            $stats[$num] = 1;
        }
    }
    return $stats;
}

function main() {
    $seed = 42;
    $length = 10;
    $seq = generate_sequence($seed, $length);
    $stats = analyze_sequence($seq);
    print_r($stats);
}

main();
?>