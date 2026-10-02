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

function calculate_p_value($observed, $samples) {
    $count = 0;
    foreach ($samples as $sample) {
        if ($sample >= $observed) {
            $count++;
        }
    }
    return $count / count($samples);
}

function generate_samples($data, $n) {
    $samples = [];
    for ($k = 0; $k < $n; $k++) {
        $permuted_data = iterator_to_array(permute($data, 0, count($data)));
        $sample = array_sum(array_rand($permuted_data, 1));
        $samples[] = $sample;
    }
    return $samples;
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $observed = array_sum($data);
    $n = 10000;
    $samples = generate_samples($data, $n);
    $p_value = calculate_p_value($observed, $samples);
    echo $p_value;
}

main();