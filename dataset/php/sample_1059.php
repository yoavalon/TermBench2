<?php

function calculate_altitude($depth, $altitude) {
    if ($depth < 0) {
        return $altitude;
    }
    return calculate_altitude($depth - 1, $altitude + 100);
}

function plan_trajectory($depth) {
    if ($depth == 0) {
        return calculate_altitude($depth, 10000);
    }
    return plan_trajectory($depth - 1);
}

function main() {
    $depth = 1;
    while (true) {
        $altitude = plan_trajectory($depth);
        echo "Depth: $depth, Altitude: $altitude\n";
        $depth += 1;
    }
}

main();