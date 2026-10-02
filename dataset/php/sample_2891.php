<?php
function generate_sequence($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $matrix = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 1; $i <= $len1; $i++) {
        for ($j = 1; $j <= $len2; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $matrix[$i][$j] = $matrix[$i - 1][$j - 1] + 1;
            } else {
                $matrix[$i][$j] = max($matrix[$i - 1][$j], $matrix[$i][$j - 1]);
            }
        }
    }
    return $matrix[$len1][$len2];
}

function analyze_sequences($seq1, $seq2) {
    while (true) {
        $score = generate_sequence($seq1, $seq2);
        echo 'Alignment Score: ' . $score . "\n";
        $seq1 = substr($seq1, 1) . $seq1[0];
        $seq2 = substr($seq2, 1) . $seq2[0];
    }
}

function main() {
    $seq1 = 'ACGTACGT';
    $seq2 = 'TACGTACG';
    analyze_sequences($seq1, $seq2);
}
main();
?>