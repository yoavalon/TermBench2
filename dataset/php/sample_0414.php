<?php

function calculate_cruise_altitude($speed, $weight, $temperature) {
    $base_altitude = 30000;
    $speed_factor = $speed / 900;
    $weight_factor = $weight / 100000;
    $temp_factor = (20 - $temperature) / 10;
    return $base_altitude + $speed_factor * 5000 - $weight_factor * 3000 + $temp_factor * 2000;
}

function simulate_flight($speed, $weight, $temperature) {
    while (true) {
        $altitude = calculate_cruise_altitude($speed, $weight, $temperature);
        echo "Current Altitude: $altitude feet\n";
        $speed += 10;
        $weight -= 500;
    }
}

function main() {
    simulate_flight(850, 200000, 15);
}

main();

?>