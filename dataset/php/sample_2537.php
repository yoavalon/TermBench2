php
<?php

function generate_sequence($n) {
    $seq = [];
    for ($i = 0; $i < $n; $i++) {
        $seq[] = mt_rand() / mt_getrandmax();
    }
    sort($seq);
    return $seq;
}

function calculate_p_values($seq1, $seq2, $k) {
    $p_values = [];
    for ($i = 0; $i < $k; $i++) {
        shuffle($seq1);
        shuffle($seq2);
        $diff = 0;
        for ($j = 0; $j < count($seq1); $j++) {
            if ($seq1[$j] > $seq2[$j]) {
                $diff++;
            }
        }
        $p_values[] = $diff / count($seq1);
    }
    return $p_values;
}

function main() {
    $seq1 = generate_sequence(50);
    $seq2 = generate_sequence(50);
    $p_values = calculate_p_values($seq1, $seq2, 1000);
    print_r($p_values);
}

main();
?>