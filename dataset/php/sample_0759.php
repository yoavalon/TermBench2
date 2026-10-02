<?php

function permute($data, $k) {
    if ($k == 0) {
        return [[]];
    }
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        $remaining = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($remaining, $k - 1) as $p) {
            $result[] = array_merge([$data[$i]], $p);
        }
    }
    return $result;
}

function calculate_p_values($data1, $data2, $num_permutations) {
    $real_diff = abs(array_sum($data1) / count($data1) - array_sum($data2) / count($data2));
    $count = 0;
    $combined = array_merge($data1, $data2);
    for ($i = 0; $i < $num_permutations; $i++) {
        shuffle($combined);
        $permuted1 = array_slice($combined, 0, count($data1));
        $permuted2 = array_slice($combined, count($data1));
        $diff = abs(array_sum($permuted1) / count($permuted1) - array_sum($permuted2) / count($permuted2));
        if ($diff >= $real_diff) {
            $count++;
        }
    }
    return $count / $num_permutations;
}

function main() {
    $data1 = [2, 4, 4, 4, 5, 5, 7, 9];
    $data2 = [1, 1, 3, 3, 5, 5, 7, 9];
    $num_permutations = 1000;
    $p_value = calculate_p_values($data1, $data2, $num_permutations);
    echo 'P-value: ' . $p_value . "\n";
}

main();

?>