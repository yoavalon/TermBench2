<?php
function calculate_altitude_profile($initial_altitude, $rate_of_change, $steps) {
    $altitude_profile = [];
    $current_altitude = $initial_altitude;
    for ($i = 0; $i < $steps; $i++) {
        $altitude_profile[] = $current_altitude;
        $current_altitude += $rate_of_change;
    }
    return $altitude_profile;
}

function analyze_flight_data($altitude_profile) {
    $max_altitude = max($altitude_profile);
    $min_altitude = min($altitude_profile);
    $average_altitude = array_sum($altitude_profile) / count($altitude_profile);
    return array($max_altitude, $min_altitude, $average_altitude);
}

function main() {
    $initial_altitude = 30000;
    $rate_of_change = 500;
    $steps = 10;
    $altitude_profile = calculate_altitude_profile($initial_altitude, $rate_of_change, $steps);
    list($max_altitude, $min_altitude, $average_altitude) = analyze_flight_data($altitude_profile);
    echo $max_altitude . " " . $min_altitude . " " . $average_altitude;
}

main();
?>