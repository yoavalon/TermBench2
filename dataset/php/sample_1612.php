<?php

function update_altitude($current_alt, $speed, $time) {
    return $current_alt + $speed * $time;
}

function adjust_speed($current_speed, $desired_alt, $current_alt) {
    if ($desired_alt > $current_alt) {
        return $current_speed + 1;
    } elseif ($desired_alt < $current_alt) {
        return $current_speed - 1;
    } else {
        return $current_speed;
    }
}

function main() {
    $alt = 0;
    $speed = 10;
    $desired_altitude = 30000;
    while (true) {
        $alt = update_altitude($alt, $speed, 1);
        $speed = adjust_speed($speed, $desired_altitude, $alt);
        if (abs($alt - $desired_altitude) < 100) {
            echo 'Cruise altitude reached: ' . $alt . "\n";
        } else {
            echo 'Current altitude: ' . $alt . "\n";
        }
    }
}

main();

?>