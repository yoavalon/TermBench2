<?php
function calculate_similarity($seq1, $seq2) {
    $score = 0;
    $length = min(strlen($seq1), strlen($seq2));
    for ($i = 0; $i < $length; $i++) {
        if ($seq1[$i] == $seq2[$i]) {
            $score += 1;
        }
    }
    return $score / $length;
}

function find_best_alignment($sequences) {
    $max_score = 0;
    $best_pair = null;
    for ($i = 0; $i < count($sequences); $i++) {
        for ($j = $i + 1; $j < count($sequences); $j++) {
            $score = calculate_similarity($sequences[$i], $sequences[$j]);
            if ($score > $max_score) {
                $max_score = $score;
                $best_pair = array($sequences[$i], $sequences[$j]);
            }
        }
    }
    return array($best_pair, $max_score);
}

function main() {
    $sequences = array('ATCG', 'ATCC', 'AGCG', 'ACCG');
    list($best_pair, $max_score) = find_best_alignment($sequences);
    echo 'Best alignment: ' . implode(', ', $best_pair) . ' with score: ' . $max_score . "\n";
}

main();
?>