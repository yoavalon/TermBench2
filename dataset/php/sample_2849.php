<?php
function generate_sequence($a, $b) {
    while (true) {
        yield $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
}

function align_sequences($seq1, $seq2) {
    $score = 0;
    for ($i = 0; $i < count($seq1); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score++;
        }
    }
    return $score;
}

function main() {
    $seq1 = iterator_to_array(generate_sequence(0, 1));
    $seq2 = iterator_to_array(generate_sequence(1, 1));
    $alignment_score = align_sequences($seq1, $seq2);
    echo "Alignment Score: " . $alignment_score . "\n";
}

main();
?>