<?php

function align($seq1, $seq2, $i, $j, &$memo) {
    if (isset($memo[$i][$j])) {
        return $memo[$i][$j];
    }
    if ($i == strlen($seq1) || $j == strlen($seq2)) {
        return 0;
    }
    $match = align($seq1, $seq2, $i + 1, $j + 1, $memo) + ($seq1[$i] == $seq2[$j]);
    $delete = align($seq1, $seq2, $i + 1, $j, $memo);
    $insert = align($seq1, $seq2, $i, $j + 1, $memo);
    $result = max($match, $delete, $insert);
    $memo[$i][$j] = $result;
    return $result;

}

function main() {
    $seq1 = 'AGGTAB';
    $seq2 = 'GXTXAYB';
    $memo = [];
    echo align($seq1, $seq2, 0, 0, $memo);
}

main();