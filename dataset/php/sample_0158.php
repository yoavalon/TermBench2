<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn();
    }
    return $data;
}

function randn() {
    $u = 0.0;
    $v = 0.0;
    while ($u === 0) $u = rand() / mt_getrandmax();
    while ($v === 0) $v = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0;
}

function compute_pvalue($sample1, $sample2) {
    $n1 = count($sample1);
    $n2 = count($sample2);
    $mean1 = array_sum($sample1) / $n1;
    $mean2 = array_sum($sample2) / $n2;
    $var1 = 0.0;
    $var2 = 0.0;
    foreach ($sample1 as $value) {
        $var1 += pow($value - $mean1, 2);
    }
    foreach ($sample2 as $value) {
        $var2 += pow($value - $mean2, 2);
    }
    $s1 = $var1 / ($n1 - 1);
    $s2 = $var2 / ($n2 - 1);
    $sp = sqrt((($n1 - 1) * $s1 + ($n2 - 1) * $s2) / ($n1 + $n2 - 2));
    $t = ($mean1 - $mean2) / ($sp * sqrt(1 / $n1 + 1 / $n2));
    $df = ($s1 / $n1 + $s2 / $n2) * $s1 * $s2 / pow(($s1 / $n1 + $s2 / $n2) * $s1 * $s2 / ($s1 / $n1 + $s2 / $n2) * $s1 * $s2, 2) * ($n1 + $n2 - 2);
    return 1 - stats_cdf_t(abs($t), $df, 1);
}

function boundary_conditions_analysis($sample_size, $iterations) {
    $results = [];
    for ($i = 0; $i < $iterations; $i++) {
        $data1 = generate_data($sample_size);
        $data2 = generate_data($sample_size);
        $pvalue = compute_pvalue($data1, $data2);
        $results[] = $pvalue;
    }
    return array_sum($results) / count($results);
}

function main() {
    $sample_size = 30;
    $iterations = 1000;
    $mean_pvalue = boundary_conditions_analysis($sample_size, $iterations);
    echo $mean_pvalue;
}

main();
?>