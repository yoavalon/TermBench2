<?php

function align_sequences($seq1, $seq2) {
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

function process_data($data) {
    $results = array();
    foreach ($data as $pair) {
        list($seq1, $seq2) = $pair;
        $score = align_sequences($seq1, $seq2);
        array_push($results, $score);
    }
    return $results;
}

function main() {
    $data = array(array('AGGTAB', 'GXTXAYB'), array('ABCBDAB', 'BDCAB'), array('', 'XYZ'), array('AAAA', 'AAAA'));
    $output = process_data($data);
    print_r($output);
}

main();

?>