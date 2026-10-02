<?php
function calculate_altitude($time) {
    if ($time < 10) {
        return 5000;
    } elseif ($time < 20) {
        return 10000;
    } else {
        return 15000;
    }
}

function simulate_flight($duration) {
    $times = range(1, $duration);
    $altitudes = array_map('calculate_altitude', $times);
    return $altitudes;
}

function main() {
    $flight_duration = 30;
    $trajectory = simulate_flight($flight_duration);
    foreach ($trajectory as $index => $altitude) {
        $time = $index + 1;
        echo "Time: $time, Altitude: $altitude\n";
    }
}

main();
?>