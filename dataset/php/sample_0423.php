<?php

function calculate_altitude($speed, $climb_rate) {
    $altitude = 0;
    while (true) {
        $altitude += $climb_rate;
        if ($altitude > 30000) {
            return $altitude;
        }
    }
}

function adjust_speed($current_speed, $target_speed) {
    if ($current_speed < $target_speed) {
        return $current_speed + 100;
    } elseif ($current_speed > $target_speed) {
        return $current_speed - 100;
    }
    return $current_speed;
}

function main() {
    $speed = 250;
    $target_speed = 350;
    $altitude = 0;
    while (true) {
        $speed = adjust_speed($speed, $target_speed);
        $altitude = calculate_altitude($speed, 1000);
        echo "Speed: $speed, Altitude: $altitude\n";
    }
}

main();
?>