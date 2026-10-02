<?php

function generate_sequence($n) {
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $i * $i + $i + 1;
    }
    return $sequence;
}

function align_sequences($seq1, $seq2) {
    $len1 = count($seq1);
    $len2 = count($seq2);
    $alignment = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 0; $i <= $len1; $i++) {
        for ($j = 0; $j <= $len2; $j++) {
            if ($i == 0 || $j == 0) {
                $alignment[$i][$j] = 0;
            } elseif ($seq1[$i - 1] == $seq2[$j - 1]) {
                $alignment[$i][$j] = $alignment[$i - 1][$j - 1] + 1;
            } else {
                $alignment[$i][$j] = max($alignment[$i - 1][$j], $alignment[$i][$j - 1]);
            }
        }
    }
    return $alignment;
}

function find_longest_common_subsequence($seq1, $seq2) {
    $alignment_matrix = align_sequences($seq1, $seq2);
    $len1 = count($seq1);
    $len2 = count($seq2);
    $lcs = [];
    while ($len1 > 0 && $len2 > 0) {
        if ($seq1[$len1 - 1] == $seq2[$len2 - 1]) {
            array_unshift($lcs, $seq1[$len1 - 1]);
            $len1 -= 1;
            $len2 -= 1;
        } elseif ($alignment_matrix[$len1 - 1][$len2] > $alignment_matrix[$len1][$len2 - 1]) {
            $len1 -= 1;
        } else {
            $len2 -= 1;
        }
    }
    return $lcs;
}

function main() {
    $seq1 = generate_sequence(10);
    $seq2 = generate_sequence(12);
    $lcs = find_longest_common_subsequence($seq1, $seq2);
    print_r($lcs);
}

main();

?>