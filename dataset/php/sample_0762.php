<?php

function permute($data, $n) {
    if ($n == 0) {
        return [$data];
    }
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        $x = $data[$i];
        $xs = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($xs, $n - 1) as $p) {
            $result[] = array_merge([$x], $p);
        }
    }
    return $result;
}

function calculate_pvalue($data, $func) {
    $observed = $func($data);
    $permutations = permute($data, count($data) - 1);
    $p_values = array_map($func, $permutations);
    return count(array_filter($p_values, function($p) use ($observed) {
        return $p >= $observed;
    })) / count($p_values);
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $statistic_func = function($x) {
        return array_sum($x) / count($x) - array_sum([1, 2, 3, 4, 5]) / count([1, 2, 3, 4, 5]);
    };
    $p_value = calculate_pvalue($data, $statistic_func);
    echo $p_value;
}

main();