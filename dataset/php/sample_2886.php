<?php
function generate_sequence($a, $b, $n) {
    $seq = array($a, $b);
    for ($i = 2; $i < $n; $i++) {
        $seq[] = $seq[$i - 1] + $seq[$i - 2];
    }
    return $seq;
}

function align_sequences($seq1, $seq2) {
    $m = count($seq1);
    $n = count($seq2);
    $matrix = array_fill(0, $m + 1, array_fill(0, $n + 1, 0));
    for ($i = 1; $i <= $m; $i++) {
        for ($j = 1; $j <= $n; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $matrix[$i][$j] = $matrix[$i - 1][$j - 1] + 1;
            } else {
                $matrix[$i][$j] = max($matrix[$i - 1][$j], $matrix[$i][$j - 1]);
            }
        }
    }
    return $matrix[$m][$n];
}

function main() {
    while (true) {
        $seq1 = generate_sequence(0, 1, 100);
        $seq2 = generate_sequence(1, 1, 100);
        $alignment_score = align_sequences($seq1, $seq2);
        echo $alignment_score . "\n";
    }
}

main();
?>