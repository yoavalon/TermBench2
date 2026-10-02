<?php
function calculate_cruise_altitude($speed, $weight, $conditions) {
    $altitude = 0;
    if ($speed > 500 && $weight < 10000) {
        $altitude = 35000;
    } elseif ($speed > 400 && $weight < 8000) {
        $altitude = 30000;
    } else {
        $altitude = 25000;
    }
    return $altitude;
}

function adjust_trajectory($altitude, $target) {
    $difference = $target - $altitude;
    if ($difference > 1000) {
        return 1000;
    } elseif ($difference < -1000) {
        return -1000;
    }
    return $difference;
}

function main() {
    $speed = 550;
    $weight = 9500;
    $target_altitude = 34000;
    $current_altitude = calculate_cruise_altitude($speed, $weight, array());
    $adjustment = adjust_trajectory($current_altitude, $target_altitude);
    echo 'Current Altitude: ' . $current_altitude . "\n";
    echo 'Adjustment Needed: ' . $adjustment . "\n";
}

main();
?>