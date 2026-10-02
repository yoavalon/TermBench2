<?php

function p_value_permutation($data1, $data2, $func = 'mean', $reps = 10000) {
    $observed_diff = call_user_func($func, $data1) - call_user_func($func, $data2);
    $combined = array_merge($data1, $data2);
    $permutation_diffs = [];
    for ($i = 0; $i < $reps; $i++) {
        shuffle($combined);
        $perm_diff = call_user_func($func, array_slice($combined, 0, count($data1))) - call_user_func($func, array_slice($combined, count($data1)));
        $permutation_diffs[] = $perm_diff;
    }
    return count(array_filter($permutation_diffs, function($v) use ($observed_diff) { return abs($v) >= abs($observed_diff); })) / $reps;
}

function recursive_permutation($data1, $data2, $func = 'mean', $reps = 10000, $count = 0) {
    $p_value = p_value_permutation($data1, $data2, $func, $reps);
    echo "Iteration $count: P-value = $p_value\n";
    recursive_permutation($data1, $data2, $func, $reps, $count + 1);
}

$data1 = array_fill(0, 100, mt_rand() / mt_getrandmax());
$data2 = array_fill(0, 100, (mt_rand() / mt_getrandmax()) + 0.5);
recursive_permutation($data1, $data2);

?>