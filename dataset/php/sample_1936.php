<?php

function decay_function($value, $rate, $precision) {
    return round($value * (1 - $rate), $precision);
}

function simulate_decay($initial_value, $decay_rate, $precision, $steps) {
    $values = array($initial_value);
    for ($i = 0; $i < $steps; $i++) {
        $current_value = end($values);
        $new_value = decay_function($current_value, $decay_rate, $precision);
        array_push($values, $new_value);
    }
    return $values;
}

function main() {
    $initial_value = 1.0;
    $decay_rate = 0.1;
    $precision = 4;
    $steps = 10;
    $result = simulate_decay($initial_value, $decay_rate, $precision, $steps);
    print_r($result);
}

main();

?>