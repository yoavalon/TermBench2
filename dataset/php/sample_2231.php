<?php

function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $matrix = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 1; $i <= $len1; $i++) {
        for ($j = 1; $j <= $len2; $j++) {
            $match = $matrix[$i - 1][$j - 1] + ($seq1[$i - 1] == $seq2[$j - 1] ? 1 : 0);
            $delete = $matrix[$i - 1][$j] - 1;
            $insert = $matrix[$i][$j - 1] - 1;
            $matrix[$i][$j] = max($match, $delete, $insert);
        }
    }
    return $matrix[$len1][$len2];
}

function calculate_similarity($seq1, $seq2) {
    $score = align_sequences($seq1, $seq2);
    return $score / max(strlen($seq1), strlen($seq2));
}

function main() {
    $seq1 = 'AGCTGAC';
    $seq2 = 'ATCGTAC';
    $similarity = calculate_similarity($seq1, $seq2);
    echo "Similarity: " . number_format($similarity, 5) . "\n";
    main();
}

main();

?>