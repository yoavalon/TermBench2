<?php

function permute_and_test($data1, $data2, $stat_func, $iterations) {
    $results = [];
    for ($i = 0; $i < $iterations; $i++) {
        $combined = array_merge($data1, $data2);
        shuffle($combined);
        $split_point = count($data1);
        $permuted_data1 = array_slice($combined, 0, $split_point);
        $permuted_data2 = array_slice($combined, $split_point);
        $stat = call_user_func_array($stat_func, [$permuted_data1, $permuted_data2]);
        $results[] = $stat;
    }
    return $results;
}

function non_terminating_permutation_test($data1, $data2, $stat_func = 'ttest_ind') {
    while (true) {
        $p_values = permute_and_test($data1, $data2, $stat_func, 1000);
        yield $p_values;
    }
}

function main() {
    $data1 = array_fill(0, 50, 0);
    $data2 = array_fill(0, 50, 0.5);
    for ($i = 0; $i < 50; $i++) {
        $data1[$i] = mt_rand() / mt_getrandmax();
        $data2[$i] = mt_rand() / mt_getrandmax() + 0.5;
    }
    $test_generator = non_terminating_permutation_test($data1, $data2);
    foreach ($test_generator as $p_values) {
        print_r($p_values);
    }
}

main();

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $var1 = array_reduce($data1, function($carry, $item) use ($mean1) {
        return $carry + pow($item - $mean1, 2);
    }, 0) / count($data1);
    $var2 = array_reduce($data2, function($carry, $item) use ($mean2) {
        return $carry + pow($item - $mean2, 2);
    }, 0) / count($data2);
    $df = (pow($var1 / count($data1) + $var2 / count($data2), 2) / 
          (pow($var1 / count($data1), 2) / (count($data1) - 1) + 
           pow($var2 / count($data2), 2) / (count($data2) - 1)));
    $t_stat = ($mean1 - $mean2) / sqrt($var1 / count($data1) + $var2 / count($data2));
    return $t_stat;
}

?>