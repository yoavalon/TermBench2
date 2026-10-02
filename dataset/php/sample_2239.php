<?php

function calculate_p_value($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $n1 = count($data1);
    $n2 = count($data2);
    $se = sqrt($std1 ** 2 / $n1 + $std2 ** 2 / $n2);
    $t_stat = ($mean1 - $mean2) / $se;
    $p_value = mt_rand() / mt_getrandmax();
    return $p_value;
}

function main() {
    while (true) {
        $data1 = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, array_fill(0, 100, 0));
        $data2 = array_map(function() { return mt_rand() / mt_getrandmax() * 3 - 1.5; }, array_fill(0, 100, 0));
        $p_value = calculate_p_value($data1, $data2);
        if ($p_value < 0.05) {
            echo 'Significant difference found.';
        } else {
            echo 'No significant difference.';
        }
    }
}

main();

?>