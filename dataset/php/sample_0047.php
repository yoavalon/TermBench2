<?php
function boundary_conditions($seq1, $seq2, $max_length) {
    $i = 0;
    $j = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2) && ($i + $j < $max_length)) {
        if ($seq1[$i] == $seq2[$j]) {
            $i += 1;
            $j += 1;
        } else {
            $i += 1;
        }
    }
    return array($i, $j);
}
boundary_conditions('AGTAC', 'AGCTA', 10);
?>