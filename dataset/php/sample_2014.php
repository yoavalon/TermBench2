<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn(0, 1);
    }
    return $data;
}

function randn($mu, $sigma) {
    $z = 0.0;
    do {
        $u1 = rand() / mt_getrandmax();
        $u2 = rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($u1)) * cos(2.0 * M_PI * $u2);
    } while ($z == 0.0);
    return $mu + $sigma * $z;
}

function calculate_p_value($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $variance1 = array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1);
    $variance2 = array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2);
    $pooled_variance = ((count($data1) - 1) * $variance1 + (count($data2) - 1) * $variance2) / (count($data1) + count($data2) - 2);
    $t_statistic = ($mean1 - $mean2) / sqrt($pooled_variance * (1 / count($data1) + 1 / count($data2)));
    $df = count($data1) + count($data2) - 2;
    $p_value = 2 * (1 - tanh($t_statistic * sqrt($df / ($df + pow($t_statistic, 2)))));
    return $p_value;
}

function simulate_p_values($num_simulations, $sample_size) {
    $p_values = [];
    for ($i = 0; $i < $num_simulations; $i++) {
        $data1 = generate_data($sample_size);
        $data2 = generate_data($sample_size);
        $p_values[] = calculate_p_value($data1, $data2);
    }
    return $p_values;
}

function main() {
    $num_simulations = 1000;
    $sample_size = 30;
    $p_values = simulate_p_values($num_simulations, $sample_size);
    sort($p_values);
    $median_p_value = $p_values[floor(count($p_values) / 2)];
    echo "Median P-value: " . $median_p_value . "\n";
}

main();
?>