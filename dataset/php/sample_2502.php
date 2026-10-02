php
<?php

function calculate_altitude_profile($initial_alt, $rate_of_change, $steps) {
    $profile = array();
    $current_alt = $initial_alt;
    for ($i = 0; $i < $steps; $i++) {
        array_push($profile, $current_alt);
        $current_alt += $rate_of_change;
    }
    return $profile;
}

function analyze_flight_profile($profile) {
    $max_alt = max($profile);
    $min_alt = min($profile);
    return array($max_alt, $min_alt);
}

function main() {
    $initial_alt = 10000;
    $rate_of_change = 500;
    $steps = 10;
    $profile = calculate_altitude_profile($initial_alt, $rate_of_change, $steps);
    list($max_alt, $min_alt) = analyze_flight_profile($profile);
    echo 'Max Altitude: ' . $max_alt . "\n";
    echo 'Min Altitude: ' . $min_alt . "\n";
}

main();

?>