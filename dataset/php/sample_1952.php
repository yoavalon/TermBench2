<?php
function calculate_temperature_change($initial_temp, $final_temp, $precision) {
    $diff = abs($final_temp - $initial_temp);
    if ($diff < $precision) {
        return 0;
    } else {
        return $diff;
    }
}

function simulate_thermodynamic_state($initial_temp, $target_temp, $precision) {
    $step = 0.01;
    $current_temp = $initial_temp;
    while (true) {
        $change = calculate_temperature_change($current_temp, $target_temp, $precision);
        if ($change == 0) {
            return $current_temp;
        }
        $current_temp += $current_temp < $target_temp ? $step : -$step;
    }
}

function main() {
    $initial_temp = 300.0;
    $target_temp = 310.0;
    $precision = 0.001;
    $result = simulate_thermodynamic_state($initial_temp, $target_temp, $precision);
    echo $result;
}

main();
?>