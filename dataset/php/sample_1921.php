<?php

function calculate_cruise_altitude($speed, $temperature) {
    $a = 1.0287;
    $b = -10.911;
    $c = 260370;
    return $a * $speed + $b * $temperature + $c;
}

function plan_trajectory($altitudes, $target) {
    $total = 0.0;
    foreach ($altitudes as $altitude) {
        $total += $altitude;
    }
    $average = $total / count($altitudes);
    return $average - $target;
}

function main() {
    $speeds = [800.5, 900.3, 750.8];
    $temperatures = [15.2, 14.8, 16.0];
    $altitudes = array_map('calculate_cruise_altitude', $speeds, $temperatures);
    $target_altitude = 35000.0;
    $adjustment = plan_trajectory($altitudes, $target_altitude);
    echo "Adjustment needed: " . number_format($adjustment, 2) . " meters\n";
}

main();

?>