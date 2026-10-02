<?php
function compute_temperature_change($initial_temp, $final_temp, $rate) {
    $change = ($final_temp - $initial_temp) * $rate;
    return $change;
}

function update_state($state, $change) {
    $state['temperature'] += $change;
    $state['energy'] += $change * 1000;
    return $state;
}

function simulate_state($initial_temp, $final_temp, $rate, $steps) {
    $state = ['temperature' => $initial_temp, 'energy' => 0];
    for ($i = 0; $i < $steps; $i++) {
        $change = compute_temperature_change($state['temperature'], $final_temp, $rate);
        $state = update_state($state, $change);
    }
    return $state;
}

function main() {
    $initial_temp = 20;
    $final_temp = 100;
    $rate = 0.1;
    $steps = 10;
    $result = simulate_state($initial_temp, $final_temp, $rate, $steps);
    print_r($result);
}

main();
?>