<?php

function calculate_altitude($speed, $rate, $time) {
    return $speed * $rate * $time;
}

function adjust_speed($current_speed, $target_altitude, $max_altitude) {
    if ($target_altitude > $max_altitude) {
        return $max_altitude / ($rate * $time);
    } else {
        return $current_speed;
    }
}

function plan_trajectory($initial_speed, $rate, $time, $max_altitude) {
    $altitude = calculate_altitude($initial_speed, $rate, $time);
    $adjusted_speed = adjust_speed($initial_speed, $altitude, $max_altitude);
    return array($adjusted_speed, $altitude);
}

function main() {
    $initial_speed = 200;
    $rate = 0.05;
    $time = 10;
    $max_altitude = 30000;
    list($adjusted_speed, $altitude) = plan_trajectory($initial_speed, $rate, $time, $max_altitude);
    echo 'Adjusted Speed: ' . $adjusted_speed . "\n";
    echo 'Altitude: ' . $altitude . "\n";
}

main();

?>