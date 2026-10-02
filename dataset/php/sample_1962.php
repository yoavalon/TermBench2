<?php

function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    if ($len1 == 0 || $len2 == 0) {
        return 0;
    }
    $score = 0;
    for ($i = 0; $i < min($len1, $len2); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1;
        }
    }
    return $score / max($len1, $len2);
}

function normalize_score($score) {
    return floor($score * 100) / 100;
}

function main() {
    $seq1 = 'ATCGTACG';
    $seq2 = 'ATCGTACC';
    $score = align_sequences($seq1, $seq2);
    $normalized_score = normalize_score($score);
    echo $normalized_score;
}

main();
?>