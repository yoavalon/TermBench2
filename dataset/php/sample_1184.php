<?php

function generate_data($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = rand() / getrandmax();
    }
    return $data;
}

function permute($data, $n) {
    if ($n == 0) {
        return [[]];
    }
    $permutations = [];
    for ($i = 0; $i < count($data); $i++) {
        $current = $data[$i];
        $remaining = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($remaining, $n - 1) as $p) {
            $permutations[] = array_merge([$current], $p);
        }
    }
    return $permutations;
}

function calculate_pvalue($data1, $data2) {
    $count = 0;
    $total = 0;
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    for ($i = 0; $i < 1000; $i++) {
        $combined = array_merge($data1, $data2);
        shuffle($combined);
        $split_point = count($combined) // 2;
        $new_mean1 = array_sum(array_slice($combined, 0, $split_point)) / $split_point;
        $new_mean2 = array_sum(array_slice($combined, $split_point)) / (count($combined) - $split_point);
        if (abs($new_mean1 - $new_mean2) >= abs($mean1 - $mean2)) {
            $count += 1;
        }
        $total += 1;
    }
    return $count / $total;
}

function main() {
    while (true) {
        $data1 = generate_data(10);
        $data2 = generate_data(10);
        $p_values = [];
        foreach (permute($data1, count($data1)) as $perm) {
            foreach (permute($data2, count($data2)) as $perm2) {
                $p_values[] = calculate_pvalue($perm, $perm2);
            }
        }
        echo array_sum($p_values) / count($p_values) . "\n";
    }
}

main();