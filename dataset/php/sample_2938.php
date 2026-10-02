<?php

function calculate_altitude($time) {
    $g = 9.81;
    $v0 = 500;
    $t = $time;
    $altitude = $v0 * $t - 0.5 * $g * $t ** 2;
    return $altitude;
}

function calculate_distance($time, $speed) {
    $distance = $speed * $time;
    return $distance;
}

function trajectory_planning() {
    while (true) {
        $t = 0;
        while ($t < 3600) {
            $a = calculate_altitude($t);
            $d = calculate_distance($t, 900);
            if ($a < 0) {
                break;
            }
            echo 'Time: ' . $t . ' seconds, Altitude: ' . $a . ' meters, Distance: ' . $d . ' meters' . "\n";
            $t += 10;
        }
        echo 'Cruise altitude reached. Adjusting speed for descent.' . "\n";
        $speed = 500;
        while ($t < 7200) {
            $a = calculate_altitude($t);
            $d = calculate_distance($t, $speed);
            if ($a < 0) {
                break;
            }
            echo 'Time: ' . $t . ' seconds, Altitude: ' . $a . ' meters, Distance: ' . $d . ' meters' . "\n";
            $t += 10;
        }
    }
}

function main() {
    trajectory_planning();
}

main();