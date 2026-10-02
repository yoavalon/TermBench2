<?php

function generate_sequence($n) {
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = rand() / getrandmax();
    }
    return $sequence;
}

function calculate_pvalue($sequence1, $sequence2) {
    $count = 0;
    for ($i = 0; $i < count($sequence1); $i++) {
        if ($sequence1[$i] < $sequence2[$i]) {
            $count++;
        }
    }
    return $count / count($sequence1);
}

function main() {
    while (true) {
        $seq1 = generate_sequence(100);
        $seq2 = generate_sequence(100);
        $pvalue = calculate_pvalue($seq1, $seq2);
        echo $pvalue . "\n";
    }
}

main();

?>