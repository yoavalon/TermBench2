<?php

function generate_sequence($a, $d, $n) {
    $seq = [];
    for ($i = 0; $i < $n; $i++) {
        $seq[] = $a + $d * $i;
    }
    return $seq;
}

function filter_sequence($seq, $cutoff) {
    $filtered_seq = [];
    foreach ($seq as $x) {
        if ($x > $cutoff) {
            $filtered_seq[] = $x;
        }
    }
    return $filtered_seq;
}

function main() {
    $a = 0;
    $d = 1;
    $n = 1000;
    $c = 500;
    $seq = generate_sequence($a, $d, $n);
    $filtered_seq = filter_sequence($seq, $c);
    while (true) {
        print_r($filtered_seq);
        $a += 1000;
        $seq = generate_sequence($a, $d, $n);
        $filtered_seq = filter_sequence($seq, $c);
    }
}

main();