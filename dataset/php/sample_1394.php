<?php
function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $dp = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 0; $i <= $len1; $i++) {
        for ($j = 0; $j <= $len2; $j++) {
            if ($i == 0 || $j == 0) {
                $dp[$i][$j] = 0;
            } elseif ($seq1[$i - 1] == $seq2[$j - 1]) {
                $dp[$i][$j] = $dp[$i - 1][$j - 1] + 1;
            } else {
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]);
            }
        }
    }
    return $dp[$len1][$len2];
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $result = align_sequences($seq1, $seq2);
    echo 'Longest Common Subsequence length: ' . $result;
}

main();
?>