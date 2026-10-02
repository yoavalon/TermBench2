<?php

function permute($data, $index, $result, &$results) {
    if ($index == count($data)) {
        $results[] = $result;
    } else {
        for ($i = 0; $i < count($data); $i++) {
            if (!in_array($data[$i], $result)) {
                $result[] = $data[$i];
                permute($data, $index + 1, $result, $results);
                array_pop($result);
            }
        }
    }
}

function calculate_pvalue($data1, $data2) {
    $combined = array_merge($data1, $data2);
    $original_mean_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $count_greater = 0;
    $permutations = [];
    permute($combined, 0, [], $permutations);
    foreach ($permutations as $perm) {
        $perm1 = array_slice($perm, 0, count($data1));
        $perm2 = array_slice($perm, count($data1));
        if (array_sum($perm1) / count($perm1) - array_sum($perm2) / count($perm2) >= $original_mean_diff) {
            $count_greater++;
        }
    }
    return $count_greater / count($permutations);
}

function main() {
    $data1 = [1, 2, 3, 4];
    $data2 = [5, 6, 7, 8];
    $pvalue = calculate_pvalue($data1, $data2);
    echo $pvalue;
}

main();

?>