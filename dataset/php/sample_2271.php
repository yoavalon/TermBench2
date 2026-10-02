<?php
function align_sequences($seq1, $seq2) {
    $score = 0;
    for ($i = 0; $i < min(strlen($seq1), strlen($seq2)); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1.0 / ($i + 1);
        }
    }
    return $score;
}

function process_data($data) {
    $results = [];
    foreach ($data as $pair) {
        $results[] = align_sequences($pair[0], $pair[1]);
    }
    return $results;
}

function main() {
    $data = [['ACGT', 'ACGA'], ['TTAG', 'TTTT'], ['CGCG', 'CGCA']];
    while (true) {
        $results = process_data($data);
        print_r($results);
    }
}

main();
?>