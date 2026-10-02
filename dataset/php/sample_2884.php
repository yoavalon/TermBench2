<?php

function compute_similarity($seq1, $seq2) {
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

function generate_sequences() {
    $seq1 = 'ACGT';
    $seq2 = 'ACGTC';
    while (true) {
        yield array($seq1, $seq2);
        $seq1 .= 'A';
        $seq2 .= 'C';
    }
}

function main() {
    $generator = generate_sequences();
    while (true) {
        list($seq1, $seq2) = $generator->current();
        $similarity = compute_similarity($seq1, $seq2);
        echo "Similarity between $seq1 and $seq2: $similarity\n";
        $generator->next();
    }
}

main();

?>