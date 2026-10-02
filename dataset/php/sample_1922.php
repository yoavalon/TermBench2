<?php

function simulate_temperature_change($initial_temp, $rate, $steps) {
    $data = array_fill(0, $steps, 0);
    for ($i = 0; $i < $steps; $i++) {
        $data[$i] = $initial_temp + $i * $rate;
    }
    return $data;
}

function analyze_data($data, $threshold) {
    $indices = array();
    foreach ($data as $index => $value) {
        if ($value > $threshold) {
            $indices[] = $index;
        }
    }
    return $indices;
}

function main() {
    $initial_temp = 300.0;
    $rate = 0.1;
    $steps = 1000;
    $threshold = 350.0;
    $data = simulate_temperature_change($initial_temp, $rate, $steps);
    $indices = analyze_data($data, $threshold);
    print_r($indices);
}

main();

?>