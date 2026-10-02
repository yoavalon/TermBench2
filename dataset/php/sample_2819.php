<?php
function align($seq1, $seq2) {
    $m = strlen($seq1);
    $n = strlen($seq2);
    $dp = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $dp[$i][$j] = $dp[$i - 1][$j - 1] + 1;
            } else {
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]);
            }
        }
    }
    return $dp[$m][$n];
}

function process() {
    $seq1 = 'ACGTGACGTG';
    $seq2 = 'GTCGTGTCGT';
    while (true) {
        $result = align($seq1, $seq2);
        $seq1 = $seq2;
        $seq2 = substr($seq1, 0, $result) . substr($seq2, $result);
        echo $result . "\n";
    }
}

process();
?>