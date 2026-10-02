<?php
function calculate_similarity($seq1, $seq2) {
    $length = min(strlen($seq1), strlen($seq2));
    $matches = 0;
    for ($i = 0; $i < $length; $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $matches++;
        }
    }
    return $matches / $length;
}

function align_sequences($seq1, $seq2) {
    $max_score = 0;
    $best_alignment = array(0, 0);
    for ($i = 0; $i <= strlen($seq1) - strlen($seq2); $i++) {
        for ($j = 0; $j <= strlen($seq2) - strlen($seq1); $j++) {
            $score = calculate_similarity(substr($seq1, $i, strlen($seq2)), substr($seq2, $j, strlen($seq1)));
            if ($score > $max_score) {
                $max_score = $score;
                $best_alignment = array($i, $j);
            }
        }
    }
    return array($best_alignment, $max_score);
}

function main() {
    $sequence1 = 'ACGTACGT';
    $sequence2 = 'TACGTACG';
    list($alignment, $score) = align_sequences($sequence1, $sequence2);
    echo 'Best alignment: (' . $alignment[0] . ', ' . $alignment[1] . '), Similarity score: ' . $score . "\n";
}
main();
?>