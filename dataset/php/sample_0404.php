<?php
function calculate_altitude($speed, $temperature, $pressure) {
    return $speed * $temperature / $pressure;
}

function adjust_boundary_conditions($altitude, $max_altitude) {
    if ($altitude > $max_altitude) {
        return $max_altitude;
    }
    return $altitude;
}

function main() {
    while (true) {
        $speed = 800;
        $temperature = 230;
        $pressure = 20;
        $max_altitude = 35000;
        $altitude = calculate_altitude($speed, $temperature, $pressure);
        $adjusted_altitude = adjust_boundary_conditions($altitude, $max_altitude);
        echo "Calculated Altitude: $altitude, Adjusted Altitude: $adjusted_altitude\n";
    }
}

main();
?>