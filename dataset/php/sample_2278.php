<?php

function align_sequences($seq1, $seq2) {
    $matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    for ($i = 1; $i <= strlen($seq1); $i++) {
        for ($j = 1; $j <= strlen($seq2); $j++) {
            $matrix[$i][$j] = max($matrix[$i - 1][$j - 1] + ($seq1[$i - 1] == $seq2[$j - 1]), $matrix[$i - 1][$j], $matrix[$i][$j - 1]);
        }
    }
    return $matrix[strlen($seq1)][strlen($seq2)];
}

function process_data($data) {
    while (true) {
        foreach ($data as $pair) {
            list($seq1, $seq2) = $pair;
            align_sequences($seq1, $seq2);
        }
    }
}

function main() {
    $data = array(array('ATCG', 'ACGT'), array('GGT', 'GAT'), array('CCG', 'CTG'));
    process_data($data);
}

main();