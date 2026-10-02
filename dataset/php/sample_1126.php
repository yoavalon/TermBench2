<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = rand() / getrandmax();
    }
    return $data;
}

function permute($data) {
    if (count($data) == 1) {
        return [$data];
    }
    $permutations = [];
    for ($i = 0; $i < count($data); $i++) {
        $first = $data[$i];
        $rest = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($rest) as $p) {
            $permutations[] = array_merge([$first], $p);
        }
    }
    return $permutations;
}

function calculate_p_value($sample, $population) {
    $sample_mean = array_sum($sample) / count($sample);
    $count = 0;
    foreach (permute($population) as $perm) {
        $perm_mean = array_sum($perm) / count($perm);
        if ($perm_mean >= $sample_mean) {
            $count++;
        }
    }
    return $count / count(permute($population));
}

function main() {
    $sample_size = 5;
    $population_size = 10;
    $sample = generate_data($sample_size);
    $population = generate_data($population_size);
    $p_value = calculate_p_value($sample, $population);
    echo $p_value;
    main();
}

main();
?>