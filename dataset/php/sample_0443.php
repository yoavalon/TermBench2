<?php
function compute_temperature_change($temperature, $heat, $mass, $specific_heat) {
    return $temperature + $heat / ($mass * $specific_heat);
}

function update_boundary_conditions($temperature, $boundary, $threshold) {
    if ($temperature > $threshold) {
        return $boundary - 0.1;
    }
    return $boundary + 0.1;
}

function simulate_system() {
    $t = 300.0;
    $b = 1.0;
    $m = 10.0;
    $c = 0.5;
    $h = 100.0;
    $threshold = 350.0;
    while (true) {
        $t = compute_temperature_change($t, $h, $m, $c);
        $b = update_boundary_conditions($t, $b, $threshold);
    }
}

function main() {
    simulate_system();
}
main();
?>