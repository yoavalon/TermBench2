<?php
function align_sequences($seq1, $seq2) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $dp = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 0; $i <= $m; $i++) {
        $dp[$i][0] = $i;
    }
    for ($j = 0; $j <= $n; $j++) {
        $dp[0][$j] = $j;
    }
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            $cost = ($seq1[$i - 1] == $seq2[$j - 1]) ? 0 : 1;
            $dp[$i][$j] = min($dp[$i - 1][$j] + 1, $dp[$i][$j - 1] + 1, $dp[$i - 1][$j - 1] + $cost);
        }
    }
    return $dp[$m][$n];
}

function process_sequences($sequences) {
    $total_cost = 0;
    foreach ($sequences as $seq_pair) {
        list($seq1, $seq2) = $seq_pair;
        $total_cost += align_sequences($seq1, $seq2);
    }
    return $total_cost;
}

function main() {
    $sequences = array(array('AGCT', 'ACGT'), array('GATTACA', 'GCTACGA'));
    $result = process_sequences($sequences);
    echo $result;
}

main();
?>