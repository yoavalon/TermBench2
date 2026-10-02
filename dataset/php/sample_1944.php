<?php
function calculate_altitude_change($current_altitude, $target_altitude, $rate) {
    $change = $target_altitude - $current_altitude;
    if (abs($change) < $rate) {
        return $target_altitude;
    }
    return $current_altitude + $rate * ($change > 0 ? 1 : -1);
}

function plan_trajectory($initial_altitude, $target_altitude, $rate, $steps) {
    $altitudes = array();
    $current_altitude = $initial_altitude;
    for ($i = 0; $i < $steps; $i++) {
        $current_altitude = calculate_altitude_change($current_altitude, $target_altitude, $rate);
        array_push($altitudes, $current_altitude);
    }
    return $altitudes;
}

function main() {
    $initial_altitude = 3000.0;
    $target_altitude = 3500.0;
    $rate = 100.0;
    $steps = 10;
    $trajectory = plan_trajectory($initial_altitude, $target_altitude, $rate, $steps);
    print_r($trajectory);
}
main();
?>