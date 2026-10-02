<?php
function generate_altitude_sequence($start, $end, $step) {
    $sequence = array();
    $current = $start;
    while ($current <= $end) {
        $sequence[] = $current;
        $current += $step;
    }
    return $sequence;
}

function calculate_flight_duration($altitudes, $speed) {
    $times = array();
    foreach ($altitudes as $altitude) {
        $times[] = $altitude / $speed;
    }
    return $times;
}

function main() {
    $start_altitude = 10000;
    $end_altitude = 40000;
    $step_size = 5000;
    $cruise_speed = 1000;
    $altitudes = generate_altitude_sequence($start_altitude, $end_altitude, $step_size);
    $durations = calculate_flight_duration($altitudes, $cruise_speed);
    foreach ($altitudes as $index => $altitude) {
        echo "Altitude: {$altitude}m, Duration: " . number_format($durations[$index], 2) . "s\n";
    }
}

main();
?>