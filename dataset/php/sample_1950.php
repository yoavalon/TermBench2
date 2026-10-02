<?php

function calculate_altitude($distance, $speed, $time) {
    return $distance / ($speed * $time);
}

function adjust_precision($altitude, $precision) {
    $factor = pow(10, $precision);
    return round($altitude * $factor) / $factor;
}

function main() {
    $dist = 1200.5;
    $spd = 300.25;
    $t = 2.0;
    $precision = 2;
    $alt = calculate_altitude($dist, $spd, $t);
    $adjusted_alt = adjust_precision($alt, $precision);
    echo "Cruise Altitude: " . $adjusted_alt;
}

main();