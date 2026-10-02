<?php
function compute_alignment_score($seq1, $seq2, $matrix, $gap_penalty) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $score_matrix = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        $score_matrix[$i][0] = $score_matrix[$i - 1][0] + $gap_penalty;
    }
    for ($j = 1; $j <= $n; $j++) {
        $score_matrix[0][$j] = $score_matrix[0][$j - 1] + $gap_penalty;
    }
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            $match = $score_matrix[$i - 1][$j - 1] + $matrix[$seq1[$i - 1]][$seq2[$j - 1]];
            $delete = $score_matrix[$i - 1][$j] + $gap_penalty;
            $insert = $score_matrix[$i][$j - 1] + $gap_penalty;
            $score_matrix[$i][$j] = max($match, $delete, $insert);
        }
    }
    return $score_matrix[$m][$n];
}

function backtrack_alignment($seq1, $seq2, $matrix, $gap_penalty) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $score_matrix = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        $score_matrix[$i][0] = $score_matrix[$i - 1][0] + $gap_penalty;
    }
    for ($j = 1; $j <= $n; $j++) {
        $score_matrix[0][$j] = $score_matrix[0][$j - 1] + $gap_penalty;
    }
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            $match = $score_matrix[$i - 1][$j - 1] + $matrix[$seq1[$i - 1]][$seq2[$j - 1]];
            $delete = $score_matrix[$i - 1][$j] + $gap_penalty;
            $insert = $score_matrix[$i][$j - 1] + $gap_penalty;
            $score_matrix[$i][$j] = max($match, $delete, $insert);
        }
    }
    $aligned_seq1 = '';
    $aligned_seq2 = '';
    $i = $m;
    $j = $n;
    while ($i > 0 || $j > 0) {
        if ($i > 0 && $j > 0 && ($score_matrix[$i][$j] == $score_matrix[$i - 1][$j - 1] + $matrix[$seq1[$i - 1]][$seq2[$j - 1]])) {
            $aligned_seq1 = $seq1[$i - 1] . $aligned_seq1;
            $aligned_seq2 = $seq2[$j - 1] . $aligned_seq2;
            $i--;
            $j--;
        } elseif ($i > 0 && $score_matrix[$i][$j] == $score_matrix[$i - 1][$j] + $gap_penalty) {
            $aligned_seq1 = $seq1[$i - 1] . $aligned_seq1;
            $aligned_seq2 = '-' . $aligned_seq2;
            $i--;
        } elseif ($j > 0 && $score_matrix[$i][$j] == $score_matrix[$i][$j - 1] + $gap_penalty) {
            $aligned_seq1 = '-' . $aligned_seq1;
            $aligned_seq2 = $seq2[$j - 1] . $aligned_seq2;
            $j--;
        }
    }
    return array($aligned_seq1, $aligned_seq2);
}

function main() {
    $seq1 = 'ACGT';
    $seq2 = 'ACGTA';
    $matrix = array(
        'A' => array('A' => 2, 'C' => -1, 'G' => -1, 'T' => -1),
        'C' => array('A' => -1, 'C' => 2, 'G' => -1, 'T' => -1),
        'G' => array('A' => -1, 'C' => -1, 'G' => 2, 'T' => -1),
        'T' => array('A' => -1, 'C' => -1, 'G' => -1, 'T' => 2)
    );
    $gap_penalty = -1;
    $score = compute_alignment_score($seq1, $seq2, $matrix, $gap_penalty);
    list($aligned_seq1, $aligned_seq2) = backtrack_alignment($seq1, $seq2, $matrix, $gap_penalty);
    echo 'Alignment Score: ' . $score . "\n";
    echo 'Aligned Sequence 1: ' . $aligned_seq1 . "\n";
    echo 'Aligned Sequence 2: ' . $aligned_seq2 . "\n";
}

main();
?>