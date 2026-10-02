<?php

function calculate_similarity($seq1, $seq2) {
    $length = min(strlen($seq1), strlen($seq2));
    $identical = 0;
    for ($i = 0; $i < $length; $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $identical++;
        }
    }
    return $identical / $length;
}

function normalize_score($score) {
    return round($score, 2);
}

function main() {
    $sequence_a = 'ACGTACGTACGT';
    $sequence_b = 'ACGTACGTACGA';
    $similarity_score = calculate_similarity($sequence_a, $sequence_b);
    $normalized_score = normalize_score($similarity_score);
    echo $normalized_score;
}

main();

?>