<?php
function calculate_altitude_sequence($initial_altitude, $increment, $steps) {
    $sequence = array();
    for ($i = 0; $i < $steps; $i++) {
        $sequence[] = $initial_altitude + $i * $increment;
    }
    return $sequence;
}

function find_optimal_cruise_altitude($altitudes, $max_fuel_consumption) {
    $optimal_altitude = max(array_filter($altitudes, function($x) use ($max_fuel_consumption) {
        return $x <= $max_fuel_consumption;
    }));
    return $optimal_altitude;
}

function main() {
    $initial = 10000;
    $increment = 1000;
    $steps = 10;
    $max_fuel = 15000;
    $altitudes = calculate_altitude_sequence($initial, $increment, $steps);
    $optimal_altitude = find_optimal_cruise_altitude($altitudes, $max_fuel);
    echo $optimal_altitude;
}

main();
?>