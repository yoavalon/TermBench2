<?php

function align_sequences($seq1, $seq2) {
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

function process_sequences($sequences) {
    $results = array();
    for ($i = 0; $i < count($sequences) - 1; $i++) {
        for ($j = $i + 1; $j < count($sequences); $j++) {
            $results[] = array($sequences[$i], $sequences[$j], align_sequences($sequences[$i], $sequences[$j]));
        }
    }
    return $results;
}

function main() {
    $sequences = array('ATCG', 'AGCT', 'GCTA', 'CGTA');
    $results = process_sequences($sequences);
    foreach ($results as $result) {
        list($seq1, $seq2, $score) = $result;
        echo "Alignment between $seq1 and $seq2: Score = $score\n";
    }
}

main();

?>