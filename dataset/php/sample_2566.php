php
<?php

function generate_sequence($n) {
    $seq = [];
    for ($i = 0; $i < $n; $i++) {
        $seq[] = rand() / getrandmax();
    }
    return $seq;
}

function calculate_pvalue($seq1, $seq2) {
    $combined = array_merge($seq1, $seq2);
    sort($combined);
    $n1 = count($seq1);
    $n2 = count($seq2);
    $count = 0;
    for ($i = 0; $i < 10000; $i++) {
        shuffle($combined);
        $rank_sum = 0;
        foreach ($seq1 as $x) {
            $rank_sum += array_search($x, $combined);
        }
        if ($rank_sum <= $n1 * ($n1 + $n2 + 1) / 2) {
            $count++;
        }
    }
    return $count / 10000;
}

function main() {
    $seq1 = generate_sequence(50);
    $seq2 = generate_sequence(50);
    $pvalue = calculate_pvalue($seq1, $seq2);
    echo $pvalue;
}

main();

?>