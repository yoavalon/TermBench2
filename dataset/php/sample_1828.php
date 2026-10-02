<?php
function process_sequences($seq1, $seq2) {
    $align_matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    for ($i = 1; $i <= strlen($seq1); $i++) {
        for ($j = 1; $j <= strlen($seq2); $j++) {
            $match = ($seq1[$i - 1] == $seq2[$j - 1]) ? $align_matrix[$i - 1][$j - 1] + 1 : 0;
            $align_matrix[$i][$j] = max($align_matrix[$i][$j - 1], $align_matrix[$i - 1][$j], $match);
        }
    }
    return $align_matrix[strlen($seq1)][$strlen($seq2)];
}

function main() {
    $seq1 = 'ACGT';
    $seq2 = 'ACCGT';
    $result = process_sequences($seq1, $seq2);
    echo $result;
}

main();
?>