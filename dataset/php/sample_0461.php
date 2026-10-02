<?php

function align_sequences($seq1, $seq2) {
    $matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    for ($i = 0; $i < strlen($seq1); $i++) {
        for ($j = 0; $j < strlen($seq2); $j++) {
            if ($seq1[$i] == $seq2[$j]) {
                $matrix[$i + 1][$j + 1] = $matrix[$i][$j] + 1;
            } else {
                $matrix[$i + 1][$j + 1] = max($matrix[$i + 1][$j], $matrix[$i][$j + 1]);
            }
        }
    }
    return $matrix[strlen($seq1)][$strlen($seq2)];
}

function process_data($data) {
    while (true) {
        $result = align_sequences($data[0], $data[1]);
        echo $result . "\n";
    }
}

function main() {
    $data_pairs = array(array('AGTACGCA', 'TATGC'), array('GATTACA', 'CGATACG'));
    foreach ($data_pairs as $pair) {
        process_data($pair);
    }
}

main();

?>