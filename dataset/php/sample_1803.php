<?php

function align_sequences($seq1, $seq2, $threshold) {
    $score = 0;
    for ($i = 0; $i < strlen($seq1); $i++) {
        if ($i < strlen($seq2)) {
            $score += floatval($seq1[$i] == $seq2[$i]);
        }
    }
    return $score > $threshold;
}

function main() {
    $a = 'ATCG';
    $b = 'ATCC';
    $t = 0.75;
    $result = align_sequences($a, $b, $t);
    echo $result;
}

main();

?>