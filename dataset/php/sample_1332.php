<?php
function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $matrix = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 0; $i <= $len1; $i++) {
        $matrix[$i][0] = $i;
    }
    for ($j = 0; $j <= $len2; $j++) {
        $matrix[0][$j] = $j;
    }
    for ($i = 1; $i <= $len1; $i++) {
        for ($j = 1; $j <= $len2; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $cost = 0;
            } else {
                $cost = 1;
            }
            $matrix[$i][$j] = min($matrix[$i - 1][$j] + 1, $matrix[$i][$j - 1] + 1, $matrix[$i - 1][$j - 1] + $cost);
        }
    }
    return $matrix[$len1][$len2];
}

function main() {
    $sequence1 = 'AGCTG';
    $sequence2 = 'AGGCT';
    $distance = align_sequences($sequence1, $sequence2);
    echo 'Edit distance: ' . $distance;
}

main();
?>