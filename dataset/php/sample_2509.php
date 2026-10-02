<?php
function compute_similarity($seq1, $seq2) {
    $length = min(strlen($seq1), strlen($seq2));
    $score = 0;
    for ($i = 0; $i < $length; $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1;
        }
    }
    return $score / $length;
}

function align_sequences($seq1, $seq2) {
    $max_score = 0;
    $best_alignment = array($seq1, $seq2);
    for ($i = 0; $i < strlen($seq2); $i++) {
        $shifted_seq = substr($seq2, $i) . substr($seq2, 0, $i);
        $score = compute_similarity($seq1, $shifted_seq);
        if ($score > $max_score) {
            $max_score = $score;
            $best_alignment = array($seq1, $shifted_seq);
        }
    }
    return $best_alignment;
}

function main() {
    $sequence1 = 'ACGTACGTAC';
    $sequence2 = 'TACGTACGTA';
    $aligned_sequences = align_sequences($sequence1, $sequence2);
    echo 'Aligned Sequences: ', implode(", ", $aligned_sequences);
}

main();
?>