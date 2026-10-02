<?php

function generate_sequence($n) {
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        $hash_value = hash('sha256', strval($i));
        $sequence[] = intval($hash_value, 16) % 1000;
    }
    return $sequence;
}

function analyze_sequence($seq) {
    $stats = [
        'min' => min($seq),
        'max' => max($seq),
        'avg' => array_sum($seq) / count($seq)
    ];
    return $stats;
}

function main() {
    $seq = generate_sequence(100);
    $stats = analyze_sequence($seq);
    print_r($stats);
}

main();