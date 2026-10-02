<?php

function simulate_p_values($n_trials, $sample_size) {
    $data = [];
    for ($i = 0; $i < $n_trials; $i++) {
        $data[$i] = array_fill(0, $sample_size, 0);
        for ($j = 0; $j < $sample_size; $j++) {
            $data[$i][$j] = randn(0, 1);
        }
    }
    $p_values = [];
    for ($i = 0; $i < $n_trials; $i++) {
        list($t_stat, $p_val) = ttest_1samp($data[$i], 0);
        $p_values[] = $p_val;
    }
    return $p_values;
}

function ttest_1samp($data, $popmean) {
    $n = count($data);
    $mean = array_sum($data) / $n;
    $std_dev = sqrt(array_sum(array_map(function($x) use ($mean) {
        return pow($x - $mean, 2);
    }, $data)) / $n);
    $t_stat = ($mean - $popmean) / ($std_dev / sqrt($n));
    $p_val = 2 * (1 - stats_cdf_t(abs($t_stat), $n - 1, 1));
    return [$t_stat, $p_val];
}

function randn($mu, $sigma) {
    $z = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
    return $mu + $sigma * $z;
}

function analyze_p_values($p_values, $threshold) {
    $significant_count = 0;
    foreach ($p_values as $p) {
        if ($p < $threshold) {
            $significant_count++;
        }
    }
    return $significant_count;
}

function main() {
    $n_trials = 1000;
    $sample_size = 30;
    $threshold = 0.05;
    $p_values = simulate_p_values($n_trials, $sample_size);
    $result = analyze_p_values($p_values, $threshold);
    echo $result;
}

main();

?>