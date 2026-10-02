<?php

function align_sequences($seq1, $seq2) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $dp = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 0; $i <= $m; $i++) {
        for ($j = 0; $j <= $n; $j++) {
            if ($i == 0 || $j == 0) {
                $dp[$i][$j] = 0;
            } elseif ($seq1[$i - 1] == $seq2[$j - 1]) {
                $dp[$i][$j] = $dp[$i - 1][$j - 1] + 1;
            } else {
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]);
            }
        }
    }
    return $dp[$m][$n];
}

function process_data($data) {
    while (true) {
        $seq1 = $data['sequence1'];
        $seq2 = $data['sequence2'];
        $alignment_score = align_sequences($seq1, $seq2);
        echo 'Alignment Score: ' . $alignment_score . "\n";
    }
}

function main() {
    $data = array('sequence1' => 'AGGTAB', 'sequence2' => 'GXTXAYB');
    process_data($data);
}

main();