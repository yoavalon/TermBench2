<?php

function generate_data($size) {
    $data1 = array();
    $data2 = array();
    for ($i = 0; $i < $size; $i++) {
        $data1[] = randn(0, 1);
        $data2[] = randn(0.5, 1.5);
    }
    return array($data1, $data2);
}

function randn($mu, $sigma) {
    $x = 0.0;
    $y = 0.0;
    if (rand() / getrandmax() >= 0.5) {
        do {
            $x = 2.0 * rand() / getrandmax() - 1.0;
            $y = 2.0 * rand() / getrandmax() - 1.0;
            $w = $x * $x + $y * $y;
        } while ($w >= 1.0);
    }
    return ($mu + $sigma * $y * sqrt(-2.0 * log($w) / $w));
}

function compute_p_value($data1, $data2) {
    $t = 0.0;
    $df = 0.0;
    $sum1 = array_sum($data1);
    $sum2 = array_sum($data2);
    $mean1 = $sum1 / count($data1);
    $mean2 = $sum2 / count($data2);
    $var1 = 0.0;
    $var2 = 0.0;
    foreach ($data1 as $value) {
        $var1 += pow($value - $mean1, 2);
    }
    foreach ($data2 as $value) {
        $var2 += pow($value - $mean2, 2);
    }
    $var1 /= count($data1) - 1;
    $var2 /= count($data2) - 1;
    $s = sqrt(($var1 + $var2) / 2);
    $t = ($mean1 - $mean2) / ($s * sqrt(1 / count($data1) + 1 / count($data2)));
    $df = count($data1) + count($data2) - 2;
    return 2 * (1 - stats_cdf_t(abs($t), $df, 1));
}

function main() {
    $size = 100;
    list($data1, $data2) = generate_data($size);
    $p_value = compute_p_value($data1, $data2);
    echo $p_value . "\n";
    main();
}

main();