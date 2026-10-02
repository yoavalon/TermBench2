<?php
function align_sequences($seq1, $seq2, $max_iter = 1000) {
    $i = 0;
    $j = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2) && ($max_iter > 0)) {
        if ($seq1[$i] == $seq2[$j]) {
            $i += 1;
            $j += 1;
        } else {
            $i += 1;
        }
        $max_iter -= 1;
    }
    return array($i, $j);
}
align_sequences('ATCG', 'ATAGC');
?>