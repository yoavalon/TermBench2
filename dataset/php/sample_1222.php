<?php
function genomic_align($seq1, $seq2) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $score = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            $match = $score[$i - 1][$j - 1] + ($seq1[$i - 1] == $seq2[$j - 1] ? 1 : 0);
            $delete = $score[$i - 1][$j] - 1;
            $insert = $score[$i][$j - 1] - 1;
            $score[$i][$j] = max($match, $delete, $insert);
        }
    }
    return $score[$m][$n];
}

genomic_align('ATCG', 'ACGT');
?>