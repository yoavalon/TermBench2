<?php

function process_signal($data) {
    $processed_data = array_map('floatval', $data);
    $n = count($processed_data);
    for ($k = 0; $k < $n; $k++) {
        $sum = 0.0;
        for ($t = 0; $t < $n; $t++) {
            $sum += $processed_data[$t] * cos(2 * pi() * $t * $k / $n) - 
                    $processed_data[$t] * sin(2 * pi() * $t * $k / $n);
        }
        $processed_data[$k] = $sum;
    }
    return $processed_data;
}

function main() {
    $data = array_fill(0, 1024, 0);
    for ($i = 0; $i < 1024; $i++) {
        $data[$i] = rand() / getrandmax();
    }
    $result = process_signal($data);
    print_r($result);
}

main();

?>