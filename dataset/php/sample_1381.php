<?php

function update_altitude($current_alt, $target_alt, $rate) {
    if ($current_alt < $target_alt) {
        return min($current_alt + $rate, $target_alt);
    } elseif ($current_alt > $target_alt) {
        return max($current_alt - $rate, $target_alt);
    }
    return $current_alt;
}

function simulate_flight() {
    $current_altitude = 0;
    $target_altitude = 35000;
    $rate_of_change = 1000;
    $max_iterations = 1000;
    for ($i = 0; $i < $max_iterations; $i++) {
        $current_altitude = update_altitude($current_altitude, $target_altitude, $rate_of_change);
        if ($current_altitude == $target_altitude) {
            break;
        }
    }
    echo 'Flight reached target altitude: ' . $current_altitude . "\n";
}

simulate_flight();

?>