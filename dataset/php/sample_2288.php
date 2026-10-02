<?php

function calculate_altitude($time, $velocity, $acceleration) {
    return $velocity * $time + 0.5 * $acceleration * pow($time, 2);
}

function adjust_altitude($current_altitude, $target_altitude, $rate_of_change) {
    $delta = $target_altitude - $current_altitude;
    return $current_altitude + min($delta, $rate_of_change);
}

function main() {
    $t = 0.0;
    $v = 250.0;
    $a = 10.0;
    $ta = 10000.0;
    $ra = 100.0;
    $current_altitude = 0.0;
    while (true) {
        $t += 0.1;
        $current_altitude = calculate_altitude($t, $v, $a);
        $current_altitude = adjust_altitude($current_altitude, $ta, $ra);
        echo sprintf('Time: %.1f, Altitude: %.2f', $t, $current_altitude) . PHP_EOL;
    }
}

main();