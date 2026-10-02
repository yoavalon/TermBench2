<?php
function calculate_altitude($speed, $wind, $max_altitude) {
    return max(0, min($max_altitude, $speed - $wind));
}

function update_trajectory($alt, $time, $descent_rate) {
    if ($alt > 0) {
        return $alt - $descent_rate * $time;
    }
    return 0;
}

function main() {
    $speed = 600;
    $wind = 50;
    $max_altitude = 30000;
    $descent_rate = 100;
    $time_step = 1;
    $current_altitude = calculate_altitude($speed, $wind, $max_altitude);
    while ($current_altitude > 0) {
        echo "Current Altitude: $current_altitude\n";
        $current_altitude = update_trajectory($current_altitude, $time_step, $descent_rate);
    }
}

main();
?>