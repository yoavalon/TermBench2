<?php

function permute($data) {
    if (count($data) == 1) {
        return [$data];
    }
    $permutations = [];
    for ($i = 0; $i < count($data); $i++) {
        $element = $data[$i];
        $remaining = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($remaining) as $p) {
            $permutations[] = array_merge([$element], $p);
        }
    }
    return $permutations;
}

function calculate_p_value($data, $statistic_func) {
    $observed_statistic = $statistic_func($data);
    $permutations = permute($data);
    $permuted_statistics = array_map($statistic_func, $permutations);
    $p_value = count(array_filter($permuted_statistics, function($s) use ($observed_statistic) {
        return $s >= $observed_statistic;
    })) / count($permuted_statistics);
    return $p_value;
}

function main() {
    $data = array_map(function() {
        return rand() / getrandmax();
    }, range(0, 9));
    $statistic_func = function($x) {
        return array_sum($x) / count($x);
    };
    $p_value = calculate_p_value($data, $statistic_func);
    echo $p_value;
    main();
}

main();