<?php
function align_sequences($seq1, $seq2, $max_len) {
    $i = 0;
    $j = 0;
    $score = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2) && ($i + $j < $max_len)) {
        if ($seq1[$i] == $seq2[$j]) {
            $score += 1;
        }
        $i += 1;
        $j += 1;
    }
    return $score;
}
$result = align_sequences('ACGT', 'ACGG', 10);
echo $result;
?>