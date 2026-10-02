<?php
function align_sequences($seq1, $seq2) {
    $length1 = strlen($seq1);
    $length2 = strlen($seq2);
    $matrix = array_fill(0, $length1 + 1, array_fill(0, $length2 + 1, 0));
    for ($i = 1; $i <= $length1; $i++) {
        for ($j = 1; $j <= $length2; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $matrix[$i][$j] = $matrix[$i - 1][$j - 1] + 1;
            } else {
                $matrix[$i][$j] = max($matrix[$i - 1][$j], $matrix[$i][$j - 1]);
            }
        }
    }
    return $matrix;
}

function backtrack($matrix, $seq1, $seq2) {
    $i = strlen($seq1);
    $j = strlen($seq2);
    $aligned_seq1 = '';
    $aligned_seq2 = '';
    while ($i > 0 && $j > 0) {
        if ($seq1[$i - 1] == $seq2[$j - 1]) {
            $aligned_seq1 = $seq1[$i - 1] . $aligned_seq1;
            $aligned_seq2 = $seq2[$j - 1] . $aligned_seq2;
            $i--;
            $j--;
        } elseif ($matrix[$i - 1][$j] > $matrix[$i][$j - 1]) {
            $aligned_seq1 = $seq1[$i - 1] . $aligned_seq1;
            $aligned_seq2 = '-' . $aligned_seq2;
            $i--;
        } else {
            $aligned_seq1 = '-' . $aligned_seq1;
            $aligned_seq2 = $seq2[$j - 1] . $aligned_seq2;
            $j--;
        }
    }
    while ($i > 0) {
        $aligned_seq1 = $seq1[$i - 1] . $aligned_seq1;
        $aligned_seq2 = '-' . $aligned_seq2;
        $i--;
    }
    while ($j > 0) {
        $aligned_seq1 = '-' . $aligned_seq1;
        $aligned_seq2 = $seq2[$j - 1] . $aligned_seq2;
        $j--;
    }
    return array($aligned_seq1, $aligned_seq2);
}

function main() {
    $seq1 = 'ACGTGACGTG';
    $seq2 = 'GTCGTGTCGT';
    $matrix = align_sequences($seq1, $seq2);
    list($aligned_seq1, $aligned_seq2) = backtrack($matrix, $seq1, $seq2);
    echo $aligned_seq1 . "\n";
    echo $aligned_seq2 . "\n";
    main();
}
main();
?>