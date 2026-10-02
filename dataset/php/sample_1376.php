<?php
function calculate_altitude($cruise_speed, $distance, $wind_speed, $wind_direction) {
    $speed = ($wind_direction == 'against') ? $cruise_speed - $wind_speed : $cruise_speed + $wind_speed;
    $time = $distance / $speed;
    $altitude = ($cruise_speed * $time) / 10;
    return $altitude;
}

function adjust_altitude($altitude, $adjustments) {
    foreach ($adjustments as $adjustment) {
        if ($adjustment > 0) {
            $altitude += $adjustment;
        } else {
            $altitude -= abs($adjustment);
        }
    }
    return $altitude;
}

function main() {
    $cruise_speed = 800;
    $distance = 2000;
    $wind_speed = 50;
    $wind_direction = 'against';
    $adjustments = [100, -50, 30];
    $initial_altitude = calculate_altitude($cruise_speed, $distance, $wind_speed, $wind_direction);
    $final_altitude = adjust_altitude($initial_altitude, $adjustments);
    echo $final_altitude;
}

main();
?>