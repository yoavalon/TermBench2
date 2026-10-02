<?php

function generate_sequence($length) {
    $sequence = array_fill(0, $length, 0);
    for ($i = 1; $i < $length; $i++) {
        $sequence[$i] = $sequence[$i - 1] + rand(1, 4);
    }
    return $sequence;
}

function vectorize_sequence($sequence) {
    $vectorizer = function($x) {
        return $x * 2;
    };
    $vec_seq = array_map($vectorizer, $sequence);
    return $vec_seq;
}

function main() {
    $seq_length = 10;
    $seq = generate_sequence($seq_length);
    $vec_seq = vectorize_sequence($seq);
    print_r($vec_seq);
}

main();