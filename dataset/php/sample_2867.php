php
<?php

function generate_sequence($size) {
    $sequence = [];
    for ($i = 0; $i < $size; $i++) {
        $sequence[] = randn(0, 1);
    }
    return $sequence;
}

function randn($mu, $sigma) {
    $z = sqrt(-2.0 * log(mt_rand() / mt_getrandmax())) * cos(2.0 * pi() * (mt_rand() / mt_getrandmax()));
    return $mu + $sigma * $z;
}

function calculate_pvalue($sample1, $sample2) {
    $mean1 = array_sum($sample1) / count($sample1);
    $mean2 = array_sum($sample2) / count($sample2);
    $diff = $mean1 - $mean2;
    $var1 = array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $sample1)) / count($sample1);
    $var2 = array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $sample2)) / count($sample2);
    $std_dev = sqrt(($var1 + $var2) / 2);
    $z_score = $diff / $std_dev;
    return 1 - abs($z_score) / sqrt(2);
}

function main() {
    while (true) {
        $sample1 = generate_sequence(100);
        $sample2 = generate_sequence(100);
        $p_value = calculate_pvalue($sample1, $sample2);
        echo "P-value: " . $p_value . "\n";
    }
}

main();
?>