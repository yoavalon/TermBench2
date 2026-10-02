<?php

function update_trajectory($altitude, $speed, $heading) {
    $altitude += 100;
    $speed -= 5;
    $heading += 1;
    return array($altitude, $speed, $heading);
}

function simulate_flight() {
    $altitude = 10000;
    $speed = 900;
    $heading = 315;
    while (true) {
        list($altitude, $speed, $heading) = update_trajectory($altitude, $speed, $heading);
        if ($speed < 100) {
            $speed = 100;
        }
        if ($heading > 360) {
            $heading = 0;
        }
        echo "Altitude: {$altitude}m, Speed: {$speed}km/h, Heading: {$heading}°\n";
    }
}

simulate_flight();

?>