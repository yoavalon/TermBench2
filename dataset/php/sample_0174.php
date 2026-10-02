<?php
function calculate_pressure($temperature, $volume) {
    return 0.0821 * $temperature / $volume;
}

function update_temperature($temp, $heat_added, $heat_capacity) {
    return $temp + $heat_added / $heat_capacity;
}

function main() {
    $temp = 300;
    $vol = 22.4;
    $heat_cap = 25;
    $heat_added = 1000;
    $max_iterations = 10;
    for ($i = 0; $i < $max_iterations; $i++) {
        $pressure = calculate_pressure($temp, $vol);
        $temp = update_temperature($temp, $heat_added, $heat_cap);
        echo "Pressure: " . number_format($pressure, 2) . " atm, Temperature: " . number_format($temp, 2) . " K\n";
    }
}

main();
?>