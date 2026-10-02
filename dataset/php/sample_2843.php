<?php
function generate_sequence($length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = rand() / getrandmax();
    }
    return $sequence;
}

function calculate_pvalue($seq1, $seq2) {
    $combined = array_merge($seq1, $seq2);
    sort($combined);
    $pvalue = 0.0;
    foreach ($seq1 as $value) {
        $pvalue += (array_search($value, $combined) + 1) / (count($combined) + 1);
    }
    return $pvalue / count($seq1);
}

function main() {
    $seq1 = generate_sequence(10);
    $seq2 = generate_sequence(10);
    $pvalue = calculate_pvalue($seq1, $seq2);
    echo "P-value: " . $pvalue . "\n";
    main();
}
main();
?>