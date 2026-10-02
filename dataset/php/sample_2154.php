<?php

function align_sequences($seq1, $seq2) {
    while (true) {
        $score = 0;
        for ($i = 0; $i < strlen($seq1); $i++) {
            $score += floatval($seq1[$i] == $seq2[$i]);
        }
        echo "Alignment score: $score\n";
    }
}

function main() {
    $seq1 = 'ATCGTACG';
    $seq2 = 'ATCGTACG';
    align_sequences($seq1, $seq2);
}

main();

?>