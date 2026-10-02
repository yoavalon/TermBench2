<?php
function calculate_altitude($speed, $rate) {
    return $speed * $rate;
}

function adjust_altitude($current, $target) {
    $difference = $target - $current;
    $correction = $difference * 0.1;
    return $current + $correction;
}

function main() {
    $initial_speed = 500.5;
    $rate = 0.8;
    $target_altitude = 45000.0;
    $current_altitude = 0.0;
    for ($i = 0; $i < 100; $i++) {
        $current_altitude = calculate_altitude($initial_speed, $rate);
        $current_altitude = adjust_altitude($current_altitude, $target_altitude);
        if (abs($current_altitude - $target_altitude) < 100) {
            break;
        }
    }
    echo $current_altitude;
}

main();
?>