<?php
function align_sequences($seq1, $seq2, $max_distance) {
    if ($max_distance < 0) {
        return -1;
    }
    $distance = 0;
    $i = 0;
    $j = 0;
    while ($i < strlen($seq1) && $j < strlen($seq2)) {
        if ($seq1[$i] != $seq2[$j]) {
            $distance += 1;
            if ($distance > $max_distance) {
                return -1;
            }
        }
        $i += 1;
        $j += 1;
    }
    return $distance;
}

function process_sequences($sequences, $max_distance) {
    $results = [];
    for ($i = 0; $i < count($sequences); $i++) {
        for ($j = $i + 1; $j < count($sequences); $j++) {
            $result = align_sequences($sequences[$i], $sequences[$j], $max_distance);
            array_push($results, $result);
        }
    }
    return $results;
}

function main() {
    $sequences = ['ATCG', 'ACGG', 'TACG', 'GCTA'];
    $max_distance = 2;
    print_r(process_sequences($sequences, $max_distance));
}

main();
?>