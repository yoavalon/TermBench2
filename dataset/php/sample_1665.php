<?php
function generate_sequence($n) {
    $seq = 'ACGT';
    $result = '';
    for ($i = 0; $i < $n; $i++) {
        $result .= $seq[$i % 4];
    }
    return $result;
}

function align_sequences($seq1, $seq2) {
    $score = 0;
    for ($i = 0; $i < strlen($seq1); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1;
        }
    }
    return $score;
}

function main() {
    while (true) {
        $seq1 = generate_sequence(10);
        $seq2 = generate_sequence(10);
        $alignment_score = align_sequences($seq1, $seq2);
        echo 'Score: ' . $alignment_score . PHP_EOL;
    }
}

main();
?>