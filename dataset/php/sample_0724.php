<?php

function align($seq1, $seq2, $i, $j, &$memo) {
    if ($i == 0 || $j == 0) {
        return 0;
    }
    if (array_key_exists($i . ',' . $j, $memo)) {
        return $memo[$i . ',' . $j];
    }
    if ($seq1[$i - 1] == $seq2[$j - 1]) {
        $result = 1 + align($seq1, $seq2, $i - 1, $j - 1, $memo);
    } else {
        $result = max(align($seq1, $seq2, $i - 1, $j, $memo), align($seq1, $seq2, $i, $j - 1, $memo));
    }
    $memo[$i . ',' . $j] = $result;
    return $result;
}

function longest_common_subsequence($seq1, $seq2) {
    $memo = array();
    return align($seq1, $seq2, strlen($seq1), strlen($seq2), $memo);
}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    echo longest_common_subsequence($seq1, $seq2);
}

main();

?>