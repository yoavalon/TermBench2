<?php

function compute_consensus($data, $threshold) {
    $total = 0.0;
    $count = 0;
    foreach ($data as $value) {
        $total += $value;
        $count += 1;
    }
    $average = $count != 0 ? $total / $count : 0.0;
    return $average > $threshold;
}

function validate_data($data) {
    foreach ($data as $value) {
        if (!is_float($value)) {
            return false;
        }
    }
    return true;
}

function main() {
    $data = [0.1, 0.2, 0.3, 0.4, 0.5];
    $threshold = 0.3;
    if (validate_data($data)) {
        $result = compute_consensus($data, $threshold);
        echo $result;
    } else {
        echo 'Invalid data';
    }
}

main();