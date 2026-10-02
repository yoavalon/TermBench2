<?php

function generate_sequence($n, $seed) {
    mt_srand($seed);
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = mt_rand() / mt_getrandmax() * 2 - 1;
    }
    return $sequence;
}

function calculate_p_value($sequence) {
    $n = count($sequence);
    $mean = array_sum($sequence) / $n;
    $variance = array_sum(array_map(function($x) use ($mean) {
        return pow($x - $mean, 2);
    }, $sequence)) / $n;
    $std_dev = sqrt($variance);
    $z_score = $mean / ($std_dev / sqrt($n));
    $p_value = 1 - erf($z_score / sqrt(2));
    return $p_value;
}

function perform_permutations($sequence, $iterations) {
    $p_values = [];
    for ($i = 0; $i < $iterations; $i++) {
        shuffle($sequence);
        $p_values[] = calculate_p_value($sequence);
    }
    return $p_values;
}

function analyze_p_values($p_values) {
    sort($p_values);
    $median_p_value = $p_values[floor(count($p_values) / 2)];
    return $median_p_value;
}

function erf($x) {
    // Approximation of the error function
    $t = 1.0 / (1.0 + 0.5 * abs($x));
    $y = 1.0 - (1.0 / (pow(pi(), 0.5))) * exp(-$x * $x) * ($t * (0.7978845608028654 + $t * (0.16657359027997265 + $t * (0.4053836133019036 + $t * (0.008462603202430178 + $t * (0.0005955634295254805 + $t * 0.00007198999877484412))))));
    return $x >= 0 ? $y : -$y;
}

function main() {
    $sequence_length = 100;
    $seed_value = 42;
    $num_iterations = 1000;
    $sequence = generate_sequence($sequence_length, $seed_value);
    $p_values = perform_permutations($sequence, $num_iterations);
    $median_p_value = analyze_p_values($p_values);
    echo "Median p-value: " . $median_p_value . "\n";
}

main();

?>