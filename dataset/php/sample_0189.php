<?php
function align_sequences($seq1, $seq2, $max_iter) {
    $score = 0;
    $i = 0;
    $j = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2) && $max_iter > 0) {
        if ($seq1[$i] == $seq2[$j]) {
            $score += 1;
        }
        $i += 1;
        $j += 1;
        $max_iter -= 1;
    }
    return $score;
}

function main() {
    $seq1 = 'AGTACGCA';
    $seq2 = 'TGACGTCA';
    $iterations = 5;
    $result = align_sequences($seq1, $seq2, $iterations);
    echo $result;
}

main();
?>