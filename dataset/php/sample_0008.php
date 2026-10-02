<?php

function permute_p_value($data1, $data2, $n_permutations = 1000) {
    $observed_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $combined = array_merge($data1, $data2);
    $permuted_diffs = array_fill(0, $n_permutations, 0);
    for ($i = 0; $i < $n_permutations; $i++) {
        shuffle($combined);
        $permuted_diffs[$i] = array_sum(array_slice($combined, 0, count($data1))) / count($data1) - array_sum(array_slice($combined, count($data1))) / count($data2);
    }
    $p_value = (count(array_filter($permuted_diffs, function($diff) use ($observed_diff) { return $diff >= $observed_diff; })) + 1) / ($n_permutations + 1);
    return $p_value;
}

$data1 = array_map(function() { return randn(); }, range(0, 49));
$data2 = array_map(function() { return randn(); }, range(0, 49));

function randn() {
    $u1 = mt_rand() / mt_getrandmax();
    $u2 = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

$result = permute_p_value($data1, $data2);
echo $result;

?>