<?php
function calculate_altitude($velocity, $distance) {
    $g = 9.81;
    return sqrt($velocity ** 2 + 2 * $g * $distance);
}

function adjust_trajectory($altitude, $speed) {
    if ($altitude > 10000) {
        return $speed * 0.95;
    } else {
        return $speed * 1.05;
    }
}

function main() {
    $velocity = 300;
    $distance = 10000;
    $altitude = calculate_altitude($velocity, $distance);
    $speed = adjust_trajectory($altitude, $velocity);
    echo 'Adjusted Speed: ' . $speed;
}

main();
?>