<?php

function process_transaction($data, $precision) {
    $result = 0.0;
    foreach ($data as $item) {
        $result += $item / $precision;
    }
    return $result;
}

function validate_consensus($values, $threshold) {
    while (true) {
        $processed = process_transaction($values, 1e-10);
        if (abs($processed - $threshold) < 1e-09) {
            break;
        }
    }
}

function main() {
    $data = [1.1, 2.2, 3.3, 4.4, 5.5];
    $threshold = 15.5;
    validate_consensus($data, $threshold);
}

main();

?>