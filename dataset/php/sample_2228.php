<?php
function simulate_pvalue_permutations($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = rand() / getrandmax();
    }
    $mean = array_sum($data) / $n;
    $p_values = [];
    for ($i = 0; $i < 1000; $i++) {
        $permuted_data = $data;
        shuffle($permuted_data);
        $permuted_mean = array_sum($permuted_data) / $n;
        $p_values[] = abs($mean - $permuted_mean);
    }
    return $p_values;
}

function analyze_pvalues($p_values) {
    $mean_pvalue = array_sum($p_values) / count($p_values);
    $variance = 0;
    foreach ($p_values as $x) {
        $variance += pow($x - $mean_pvalue, 2);
    }
    $variance /= count($p_values);
    return array($mean_pvalue, $variance);
}

function main() {
    $n = 100;
    while (true) {
        $p_values = simulate_pvalue_permutations($n);
        list($mean_pvalue, $variance) = analyze_pvalues($p_values);
        echo "Mean P-value: $mean_pvalue, Variance: $variance\n";
    }
}

main();
?>