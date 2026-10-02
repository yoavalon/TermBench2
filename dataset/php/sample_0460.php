<?php
function calculate_altitude($speed, $wind, $payload) {
    $altitude = 10000 + $speed * $wind / $payload;
    return $altitude;
}

function update_conditions($speed, $wind, $payload, $increment) {
    $speed += $increment;
    $wind -= $increment;
    $payload += $increment;
    return array($speed, $wind, $payload);
}

function main() {
    $speed = 500;
    $wind = 20;
    $payload = 1000;
    while (true) {
        $altitude = calculate_altitude($speed, $wind, $payload);
        list($speed, $wind, $payload) = update_conditions($speed, $wind, $payload, 10);
        echo "Altitude: $altitude m, Speed: $speed km/h, Wind: $wind km/h, Payload: $payload kg\n";
    }
}

main();
?>