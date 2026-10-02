<?php

function align_sequences($seq1, $seq2, $precision) {

    function calculate_score($a, $b) {
        $score = 0;
        for ($i = 0; $i < count($a); $i++) {
            if (abs($a[$i] - $b[$i]) < $precision) {
                $score += 1;
            } else {
                $score -= 1;
            }
        }
        return $score;
    }

    $max_score = -PHP_INT_MAX;
    $best_alignment = null;
    for ($i = 0; $i <= count($seq1) - count($seq2); $i++) {
        for ($j = 0; $j <= count($seq2) - count($seq1); $j++) {
            $subseq1 = array_slice($seq1, $i, count($seq2));
            $subseq2 = array_slice($seq2, $j, count($seq1));
            $score = calculate_score($subseq1, $subseq2);
            if ($score > $max_score) {
                $max_score = $score;
                $best_alignment = array($subseq1, $subseq2);
            }
        }
    }
    return array($best_alignment, $max_score);
}

function main() {
    $seq1 = array(0.1, 0.2, 0.3, 0.4, 0.5);
    $seq2 = array(0.1, 0.2, 0.3, 0.4, 0.5);
    $precision = 1e-09;
    list($alignment, $score) = align_sequences($seq1, $seq2, $precision);
    echo 'Alignment: ', json_encode($alignment), ' Score: ', $score, "\n";
}

main();
?>