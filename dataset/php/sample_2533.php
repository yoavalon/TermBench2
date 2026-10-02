<?php
function calculate_altitude_sequence($initial_altitude, $rate_of_climb, $steps) {
    $sequence = array();
    $current_altitude = $initial_altitude;
    for ($i = 0; $i < $steps; $i++) {
        array_push($sequence, $current_altitude);
        $current_altitude += $rate_of_climb;
    }
    return $sequence;
}

function analyze_sequence($sequence) {
    $max_altitude = max($sequence);
    $min_altitude = min($sequence);
    $average_altitude = array_sum($sequence) / count($sequence);
    return array($max_altitude, $min_altitude, $average_altitude);
}

function main() {
    $initial = 1000;
    $rate = 500;
    $steps = 5;
    $sequence = calculate_altitude_sequence($initial, $rate, $steps);
    list($max_alt, $min_alt, $avg_alt) = analyze_sequence($sequence);
    echo "Max Altitude: $max_alt, Min Altitude: $min_alt, Average Altitude: $avg_alt\n";
}

main();
?>