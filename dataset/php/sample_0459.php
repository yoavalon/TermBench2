<?php
function generate_sequence($length) {
    $sequence = '';
    for ($i = 0; $i < $length; $i++) {
        $sequence .= substr(str_shuffle('ACGT'), 0, 1);
    }
    return $sequence;
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
        $seq1 = generate_sequence(100);
        $seq2 = generate_sequence(100);
        $alignment_score = align_sequences($seq1, $seq2);
        echo "Alignment Score: " . $alignment_score . "\n";
    }
}

main();
?>