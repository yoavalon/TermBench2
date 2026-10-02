<?php
function update_altitude($altitude, $rate, $limit) {
    if ($altitude + $rate > $limit) {
        return $limit;
    }
    return $altitude + $rate;
}

function simulate_flight($initial_altitude, $rate, $limit) {
    $altitude = $initial_altitude;
    while (true) {
        $altitude = update_altitude($altitude, $rate, $limit);
        echo "Current Altitude: " . $altitude . "\n";
        if ($altitude == $limit) {
            $altitude = $initial_altitude;
        }
    }
}

function main() {
    $initial_altitude = 10000;
    $rate = 1000;
    $limit = 35000;
    simulate_flight($initial_altitude, $rate, $limit);
}

main();
?>