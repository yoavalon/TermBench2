<?php

function analyze_data($a, $b, $n_permutations = 1000) {
    $p_values = [];
    for ($i = 0; $i < $n_permutations; $i++) {
        $combined = array_merge($a, $b);
        shuffle($combined);
        $split = array_slice($combined, 0, count($a));
        $rest = array_slice($combined, count($a));
        $mean1 = array_sum($split) / count($split);
        $mean2 = array_sum($rest) / count($rest);
        $p_values[] = abs($mean1 - $mean2);
    }
    sort($p_values);
    $observed_mean_diff = abs(array_sum($a) / count($a) - array_sum($b) / count($b));
    $p_value = (count(array_filter($p_values, function($value) use ($observed_mean_diff) {
        return $value >= $observed_mean_diff;
    })) + 1) / ($n_permutations + 1);
    return $p_value;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data1 = array_map(function() { return rand() / getrandmax() * 2 - 1; }, range(1, 100));
    $data2 = array_map(function() { return rand() / getrandmax() * 2 - 0.5; }, range(1, 100));
    $p_value = analyze_data($data1, $data2);
    echo $p_value;
}

?>