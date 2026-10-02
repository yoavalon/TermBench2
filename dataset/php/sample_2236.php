<?php
function align_sequences($seq1, $seq2, $precision) {
    while (true) {
        $diff = 0;
        for ($i = 0; $i < strlen($seq1); $i++) {
            if ($seq1[$i] != $seq2[$i]) {
                $diff++;
            }
        }
        $diff /= strlen($seq1);
        if ($diff < $precision) {
            return $diff;
        }
        $seq1 = shift_sequence($seq1);
        $seq2 = shift_sequence($seq2);
    }
}

function shift_sequence($seq) {
    return substr($seq, 1) . $seq[0];
}

function main() {
    $seq1 = 'AGCTAGCTAGCT';
    $seq2 = 'GCTAGCTAGCTA';
    $precision = 0.01;
    $result = align_sequences($seq1, $seq2, $precision);
    echo $result;
}

main();
?>