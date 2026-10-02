<?php

function permute($data, $i, $length) {
    if ($i == $length) {
        yield $data;
    } else {
        for ($j = $i; $j < $length; $j++) {
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
            yield from permute($data, $i + 1, $length);
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
        }
    }
}

function calculate_pvalue($sample, $permutations) {
    $mean_original = array_sum($sample) / count($sample);
    $count = 0;
    foreach ($permutations as $perm) {
        $mean_perm = array_sum($perm) / count($perm);
        if ($mean_perm >= $mean_original) {
            $count++;
        }
    }
    return $count / count($permutations);
}

function main() {
    $sample = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(0, 9));
    $permutations = iterator_to_array(permute($sample, 0, count($sample)));
    $pvalue = calculate_pvalue($sample, $permutations);
    echo $pvalue . "\n";
    main();
}

main();

?>