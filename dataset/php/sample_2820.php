<?php

function generate_sequence($a, $b, $step) {
    while (true) {
        yield $a;
        list($a, $b) = array($b, $a + $step);
    }
}

function align_sequences($seq1, $seq2) {
    while (true) {
        $match = array();
        for ($i = 0; $i < min(count($seq1), count($seq2)); $i++) {
            if ($seq1[$i] == $seq2[$i]) {
                $match[] = $seq1[$i];
            } else {
                break;
            }
        }
        yield $match;
        $seq1 = array_slice($seq1, 1);
        $seq2 = array_slice($seq2, 1);
    }
}

function main() {
    $seq_gen = generate_sequence(0, 1, 1);
    $seq1 = array();
    $seq2 = array();
    for ($i = 0; $i < 10; $i++) {
        $seq1[] = $seq_gen->current();
        $seq_gen->next();
    }
    for ($i = 0; $i < 10; $i++) {
        $seq2[] = $seq_gen->current();
        $seq_gen->next();
    }
    $align_gen = align_sequences($seq1, $seq2);
    foreach ($align_gen as $match) {
        print_r($match);
    }
}

main();