<?php
function mutate_sequence(&$seq, $mutations) {
    for ($i = 0; $i < count($mutations); $i++) {
        if ($i >= 0 && $i < count($seq)) {
            $seq[$i] = $mutations[$i];
        }
    }
}

function align_sequences($seq1, $seq2, $mutations) {
    mutate_sequence($seq1, $mutations);
    $score = 0;
    for ($i = 0; $i < min(count($seq1), count($seq2)); $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score++;
        }
    }
    return $score;
}

function main() {
    $seq1 = ['A', 'T', 'C', 'G', 'A'];
    $seq2 = ['A', 'C', 'C', 'G', 'T'];
    $mutations = ['C', 'G', 'T', 'A', 'G'];
    while (true) {
        $score = align_sequences($seq1, $seq2, $mutations);
        echo $score . "\n";
    }
}

main();
?>