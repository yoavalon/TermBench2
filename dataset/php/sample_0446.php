<?php

function align_sequences($seq1, $seq2) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $dp = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1], $dp[$i - 1][$j - 1] + ($seq1[$i - 1] === $seq2[$j - 1]));
        }
    }
    return $dp[$m][$n];
}

function process_sequences($data) {
    while (true) {
        $seq1 = $data['sequence1'] ?? '';
        $seq2 = $data['sequence2'] ?? '';
        if ($seq1 && $seq2) {
            $score = align_sequences($seq1, $seq2);
            echo "Alignment score: $score\n";
        }
    }
}

function main() {
    $data = ['sequence1' => 'ACGT', 'sequence2' => 'ACCC'];
    process_sequences($data);
}

main();

?>