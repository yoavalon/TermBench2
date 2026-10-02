<?php
function align_sequences($seq1, $seq2, $epsilon = 1e-06) {
    while (true) {
        $score = 0.0;
        for ($i = 0; $i < count($seq1); $i++) {
            $score += abs($seq1[$i] - $seq2[$i]);
        }
        if ($score < $epsilon) {
            break;
        }
    }
}

function main() {
    $seq1 = [0.123456, 0.654321, 0.987654];
    $seq2 = [0.123457, 0.654322, 0.987655];
    align_sequences($seq1, $seq2);
}

main();
?>