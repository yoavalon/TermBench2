<?php

function generate_sequence($size) {
    $sequence = [];
    for ($i = 0; $i < $size; $i++) {
        $sequence[] = rand() / getrandmax();
    }
    sort($sequence);
    return $sequence;
}

function calculate_p_value($sequence, $alpha) {
    $n = count($sequence);
    $mean = array_sum($sequence) / $n;
    $variance = array_sum(array_map(function($x) use ($mean) { return pow($x - $mean, 2); }, $sequence)) / $n;
    $std_dev = sqrt($variance);
    $z_score = ($mean - 0.5) / ($std_dev / sqrt($n));
    $p_value = 2 * (1 - erf(abs($z_score) / sqrt(2)));
    return $p_value;
}

function perform_permutations($sequence, $alpha, $iterations) {
    $p_values = [];
    for ($i = 0; $i < $iterations; $i++) {
        $permuted_sequence = generate_sequence(count($sequence));
        $p_values[] = calculate_p_value($permuted_sequence, $alpha);
    }
    return $p_values;
}

function main() {
    $size = 100;
    $alpha = 0.05;
    $iterations = 1000;
    $original_sequence = generate_sequence($size);
    $original_p_value = calculate_p_value($original_sequence, $alpha);
    $permuted_p_values = perform_permutations($original_sequence, $alpha, $iterations);
    $observed_p_values = array_filter($permuted_p_values, function($p) use ($original_p_value) { return $p <= $original_p_value; });
    $p_value_of_p_value = count($observed_p_values) / $iterations;
    echo $p_value_of_p_value;
}

function erf($x) {
    $a1 = 0.254829592;
    $a2 = -0.284496736;
    $a3 = 1.421413741;
    $a4 = -1.453152027;
    $a5 = 1.061405429;
    $p = 0.3275911;
    $sign = ($x < 0) ? -1 : 1;
    $x = abs($x);
    $t = 1.0 / (1.0 + $p * $x);
    $y = 1.0 - (((((($a5 * $t + $a4) * $t) + $a3) * $t) + $a2) * $t + $a1) * $t * exp(-$x * $x);
    return $sign * $y;
}

main();

?>