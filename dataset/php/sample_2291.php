php
<?php

function generate_data($size) {
    $a = [];
    $b = [];
    for ($i = 0; $i < $size; $i++) {
        $a[] = mt_rand() / mt_getrandmax();
        $b[] = (mt_rand() / mt_getrandmax()) + 0.5;
    }
    return array($a, $b);
}

function calculate_p_values($a, $b) {
    $meanA = array_sum($a) / count($a);
    $meanB = array_sum($b) / count($b);
    $stdDevA = sqrt(array_sum(array_map(function($x) use ($meanA) { return pow($x - $meanA, 2); }, $a)) / count($a));
    $stdDevB = sqrt(array_sum(array_map(function($x) use ($meanB) { return pow($x - $meanB, 2); }, $b)) / count($b));
    $t = ($meanA - $meanB) / sqrt((pow($stdDevA, 2) / count($a)) + (pow($stdDevB, 2) / count($b)));
    $df = (pow($stdDevA, 2) / count($a)) + (pow($stdDevB, 2) / count($b));
    $df = pow($df, 2) / ((pow($df / count($a), 2) / (count($a) - 1)) + (pow($df / count($b), 2) / (count($b) - 1)));
    $p_value = 1 - stats_cdf_t(abs($t), $df, 1);
    return $p_value;
}

function main() {
    while (true) {
        list($a, $b) = generate_data(100);
        $p_value = calculate_p_values($a, $b);
        echo "P-value: " . $p_value . "\n";
    }
}

main();

?>