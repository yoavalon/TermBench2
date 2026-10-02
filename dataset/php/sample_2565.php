<?php
function calculate_alignment_score($seq1, $seq2) {
    $score = 0;
    for ($i = 0; $i < min(strlen($seq1), strlen($seq2)); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1;
        }
    }
    return $score;
}

function find_best_alignment($seq1, $seq2) {
    $best_score = 0;
    $best_offset = 0;
    for ($offset = -$len(seq2); $offset < strlen($seq1); $offset++) {
        $shifted_seq2 = substr($seq2, max(0, -$offset), strlen($seq2) - max(0, $offset));
        $score = calculate_alignment_score($seq1, $shifted_seq2);
        if ($score > $best_score) {
            $best_score = $score;
            $best_offset = $offset;
        }
    }
    return array($best_score, $best_offset);
}

function main() {
    $sequence1 = 'ACGTACGTACG';
    $sequence2 = 'GTACGTACGTA';
    list($score, $offset) = find_best_alignment($sequence1, $sequence2);
    echo 'Best alignment score: ' . $score . ', Offset: ' . $offset . "\n";
}

main();
?>