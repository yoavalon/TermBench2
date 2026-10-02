<?php
function calculate_altitude_profile($distance, $speed, $rate_of_climb, $cruise_altitude, $descent_rate) {
    $times = array();
    $altitudes = array();
    $current_time = 0;
    $current_altitude = 0;
    while ($current_time < $distance / $speed) {
        if ($current_altitude < $rate_of_climb * $current_time) {
            $current_altitude = $rate_of_climb * $current_time;
        } elseif ($current_altitude < $cruise_altitude) {
            $current_altitude = $cruise_altitude;
        } else {
            $current_altitude -= $descent_rate * ($current_time - $cruise_altitude / $rate_of_climb);
        }
        $times[] = $current_time;
        $altitudes[] = $current_altitude;
        $current_time += 1;
    }
    return array($times, $altitudes);
}

function analyze_flight_profile($times, $altitudes) {
    $max_altitude = max($altitudes);
    $cruise_start_time = $times[array_search($cruise_altitude, $altitudes)];
    $descent_start_time = end($times);
    return array($max_altitude, $cruise_start_time, $descent_start_time);
}

function main() {
    $distance = 1000;
    $speed = 800;
    $rate_of_climb = 100;
    $cruise_altitude = 10000;
    $descent_rate = 50;
    list($times, $altitudes) = calculate_altitude_profile($distance, $speed, $rate_of_climb, $cruise_altitude, $descent_rate);
    list($max_altitude, $cruise_start_time, $descent_start_time) = analyze_flight_profile($times, $altitudes);
    echo "Maximum Altitude: " . $max_altitude . " meters\n";
    echo "Cruise Start Time: " . $cruise_start_time . " seconds\n";
    echo "Descent Start Time: " . $descent_start_time . " seconds\n";
}

main();
?>