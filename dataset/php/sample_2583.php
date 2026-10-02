<?php
function generate_sequence($n) {
    $sequence = [];
    for ($i = 1; $i <= $n; $i++) {
        $term = $i * ($i + 1) // 2;
        array_push($sequence, $term);
    }
    return $sequence;
}

function analyze_sequence($seq) {
    $max_term = max($seq);
    $min_term = min($seq);
    $avg_term = array_sum($seq) / count($seq);
    return array($max_term, $min_term, $avg_term);
}

function main() {
    $n = 10;
    $seq = generate_sequence($n);
    list($max_t, $min_t, $avg_t) = analyze_sequence($seq);
    echo "Max: $max_t, Min: $min_t, Avg: $avg_t";
}

main();
?>