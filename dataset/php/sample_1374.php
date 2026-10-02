<?php

function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $dp = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 1; $i <= $len1; $i++) {
        for ($j = 1; $j <= $len2; $j++) {
            if ($seq1[$i - 1] == $seq2[$j - 1]) {
                $dp[$i][$j] = $dp[$i - 1][$j - 1] + 1;
            } else {
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]);
            }
        }
    }
    return $dp[$len1][$len2];
}

function process_data($data) {
    $results = array();
    foreach ($data as $pair) {
        $score = align_sequences($pair[0], $pair[1]);
        array_push($results, $score);
    }
    return $results;
}

function main() {
    $data = array(array('AGGTAB', 'GXTXAYB'), array('ABCDGH', 'AEDFHR'), array('XYZ', 'XYZ'));
    $output = process_data($data);
    print_r($output);
}

main();

?>