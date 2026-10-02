<?php

function calculate_altitude_change($current_alt, $target_alt, $rate) {
    if ($current_alt < $target_alt) {
        return min($current_alt + $rate, $target_alt);
    } else {
        return max($current_alt - $rate, $target_alt);
    }
}

function simulate_flight_trajectory($initial_alt, $target_alt, $rate, $steps) {
    $altitude = $initial_alt;
    $trajectory = [$altitude];
    for ($i = 0; $i < $steps; $i++) {
        $altitude = calculate_altitude_change($altitude, $target_alt, $rate);
        $trajectory[] = $altitude;
        if ($altitude == $target_alt) {
            break;
        }
    }
    return $trajectory;
}

function main() {
    $initial_altitude = 10000;
    $target_altitude = 30000;
    $rate_of_change = 1500;
    $simulation_steps = 100;
    $result = simulate_flight_trajectory($initial_altitude, $target_altitude, $rate_of_change, $simulation_steps);
    print_r($result);
}

main();
?>