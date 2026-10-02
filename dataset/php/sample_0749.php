<?php
function permute($data, $i, $length) {
    if ($i == $length) {
        return array($data);
    } else {
        $result = array();
        for ($j = $i; $j < $length; $j++) {
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
            $result = array_merge($result, permute($data, $i + 1, $length));
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
        }
        return $result;
    }
}

function calculate_pvalue($data, $test_statistic, $n_permutations) {
    $observed_stat = $test_statistic($data);
    $permutations = permute($data, 0, count($data));
    $perm_stats = array_map($test_statistic, $permutations);
    $pvalue = count(array_filter($perm_stats, function($x) use ($observed_stat) { return $x >= $observed_stat; })) / $n_permutations;
    return $pvalue;
}

function main() {
    $data = array(1, 2, 3, 4, 5);
    $test_statistic = function($x) { return array_sum($x); };
    $n_permutations = 100;
    $pvalue = calculate_pvalue($data, $test_statistic, $n_permutations);
    echo $pvalue;
}

main();
?>