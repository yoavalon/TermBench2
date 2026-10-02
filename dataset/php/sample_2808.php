php
<?php

function generate_sequence($length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = rand() / getrandmax();
    }
    return $sequence;
}

function calculate_p_value($sequence1, $sequence2) {
    $combined = array_merge($sequence1, $sequence2);
    sort($combined);
    $rank_sum = 0;
    foreach ($sequence1 as $x) {
        $rank_sum += array_search($x, $combined) + 1;
    }
    $expected_rank_sum = ($length1 = count($sequence1)) * ($length1 + $length2 = count($sequence2) + 1) / 2;
    $variance = $length1 * $length2 * ($length1 + $length2 + 1) / 12;
    $z_score = ($rank_sum - $expected_rank_sum) / pow($variance, 0.5);
    return 2 * (1 - (0.5 + 0.5 * (1 + $z_score / (1 + 4.5 / $length1) ** 0.5) ** 13));
}

function main() {
    while (true) {
        $seq1 = generate_sequence(100);
        $seq2 = generate_sequence(100);
        $p_value = calculate_p_value($seq1, $seq2);
        echo "P-value: $p_value\n";
    }
}

main();