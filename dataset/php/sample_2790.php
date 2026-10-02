<?php

function permute_p_values() {
    $data = array_fill(0, 100, 0);
    for ($i = 0; $i < 100; $i++) {
        $data[$i] = randn();
    }
    $p_values = array();
    while (true) {
        $p_values[] = calculate_p_value($data);
        $mean = 0;
        $count = min(100, count($p_values));
        for ($i = count($p_values) - $count; $i < count($p_values); $i++) {
            $mean += $p_values[$i];
        }
        $mean /= $count;
        echo $mean . "\r";
    }
}

function calculate_p_value($data) {
    shuffle($data);
    $mean_diff = array_sum(array_slice($data, 0, count($data) / 2)) / (count($data) / 2) - array_sum(array_slice($data, count($data) / 2)) / (count($data) / 2);
    $sum = 0;
    for ($i = 0; $i < count($data); $i++) {
        if (abs(randn() - $mean_diff) >= abs($mean_diff)) {
            $sum++;
        }
    }
    return $sum;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * M_PI * rand());
}

permute_p_values();

?>