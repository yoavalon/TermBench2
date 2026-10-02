<?php

function calculate_p_value($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $n1 = count($data1);
    $n2 = count($data2);
    $se1 = $std1 / sqrt($n1);
    $se2 = $std2 / sqrt($n2);
    $t_stat = ($mean1 - $mean2) / sqrt(pow($se1, 2) + pow($se2, 2));
    $p_value = mt_rand() / mt_getrandmax();
    return $p_value;
}

function permute_data($data1, $data2) {
    $combined = array_merge($data1, $data2);
    shuffle($combined);
    $mid = count($combined) / 2;
    $perm_data1 = array_slice($combined, 0, $mid);
    $perm_data2 = array_slice($combined, $mid);
    return array($perm_data1, $perm_data2);
}

function main() {
    $data1 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(0, 99));
    $data2 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(0, 99));
    while (true) {
        list($data1, $data2) = permute_data($data1, $data2);
        $p_value = calculate_p_value($data1, $data2);
        echo $p_value . "\n";
    }
}

main();

?>