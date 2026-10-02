<?php

function generate_sequence($length) {
    $sequence = array();
    $a = 0;
    $b = 1;
    while (count($sequence) < $length) {
        $sequence[] = $a;
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
    }
    return $sequence;
}

function align_sequences($seq1, $seq2) {
    $matrix = array();
    for ($i = 0; $i <= count($seq1); $i++) {
        $matrix[$i] = array_fill(0, count($seq2) + 1, 0);
    }
    for ($i = 1; $i <= count($seq1); $i++) {
        for ($j = 1; $j <= count($seq2); $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $matrix[$i][$j] = $matrix[$i - 1][$j - 1] + 1;
            } else {
                $matrix[$i][$j] = max($matrix[$i - 1][$j], $matrix[$i][$j - 1]);
            }
        }
    }
    return $matrix[count($seq1)][count($seq2)];
}

function main() {
    while (true) {
        $seq1 = generate_sequence(10);
        $seq2 = generate_sequence(10);
        $score = align_sequences($seq1, $seq2);
        echo "Alignment score: " . $score . "\n";
    }
}

main();
?>