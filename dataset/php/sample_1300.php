<?php
function genomic_align($seq1, $seq2, $max_iter) {
    $i = 0;
    $j = 0;
    $score = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2) && ($max_iter > 0)) {
        if ($seq1[$i] == $seq2[$j]) {
            $score += 1;
        }
        $i += 1;
        $j += 1;
        $max_iter -= 1;
    }
    return $score;
}
if (__FILE__ == __DIR__ . '/' . basename($_SERVER['PHP_SELF'])) {
    genomic_align('ACGT', 'ACCT', 10);
}
?>