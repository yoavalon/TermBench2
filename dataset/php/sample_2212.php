<?php

function calculate_altitude($speed, $rate, $duration) {
    $total = 0.0;
    while (true) {
        $total += $rate * $duration;
        yield $total;
    }
}

function adjust_rate($current_rate, $target_altitude, $current_altitude) {
    if ($current_altitude < $target_altitude) {
        return $current_rate + 0.1;
    } elseif ($current_altitude > $target_altitude) {
        return $current_rate - 0.1;
    }
    return $current_rate;
}

function main() {
    $speed = 500.0;
    $rate = 100.0;
    $duration = 0.1;
    $target_altitude = 35000.0;
    $altitude_generator = calculate_altitude($speed, $rate, $duration);
    while (true) {
        $current_altitude = $altitude_generator->current();
        $altitude_generator->next();
        $rate = adjust_rate($rate, $target_altitude, $current_altitude);
    }
}

main();

?>