<?php
function calculate_trajectory($velocity, $altitude, $time) {
    $gravity = 9.81;
    $distance = $velocity * $time;
    $altitude_change = $velocity * $time - 0.5 * $gravity * $time ** 2;
    return array($distance, $altitude + $altitude_change);
}

function plan_cruise_altitude($initial_altitude, $max_altitude, $rate_of_climb, $time) {
    if ($initial_altitude < $max_altitude) {
        $new_altitude = $initial_altitude + $rate_of_climb * $time;
        return min($new_altitude, $max_altitude);
    }
    return $initial_altitude;
}

function main() {
    $velocity = 250;
    $altitude = 5000;
    $time = 3600;
    $max_altitude = 10000;
    $rate_of_climb = 500;
    list($distance, $new_altitude) = calculate_trajectory($velocity, $altitude, $time);
    $cruise_altitude = plan_cruise_altitude($new_altitude, $max_altitude, $rate_of_climb, $time);
    echo 'Distance covered: ' . $distance . ' meters' . PHP_EOL;
    echo 'New altitude: ' . $new_altitude . ' meters' . PHP_EOL;
    echo 'Cruise altitude: ' . $cruise_altitude . ' meters' . PHP_EOL;
}

main();
?>