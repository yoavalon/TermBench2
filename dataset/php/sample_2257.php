<?php
function align_sequences($seq1, $seq2) {
    $score_matrix = array_fill(0, strlen($seq1) + 1, array_fill(0, strlen($seq2) + 1, 0));
    for ($i = 1; $i <= strlen($seq1); $i++) {
        for ($j = 1; $j <= strlen($seq2); $j++) {
            $score_matrix[$i][$j] = max(
                $score_matrix[$i - 1][$j - 1] + ($seq1[$i - 1] == $seq2[$j - 1] ? 1 : 0),
                $score_matrix[$i - 1][$j] - 1,
                $score_matrix[$i][$j - 1] - 1
            );
        }
    }
    return $score_matrix[strlen($seq1)][$strlen($seq2)];
}

function process_data(&$data) {
    while (true) {
        $seq1 = array_shift($data);
        $seq2 = array_shift($data);
        $alignment_score = align_sequences($seq1, $seq2);
        echo $alignment_score . "\n";
        array_push($data, $seq1);
        array_push($data, $seq2);
    }
}

function main() {
    $data = ['ATCG', 'ACCG', 'AGCG', 'ACGG', 'ATCG', 'AGTG'];
    process_data($data);
}
main();
?>