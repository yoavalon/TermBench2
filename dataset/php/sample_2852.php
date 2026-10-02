<?php

function calculate_altitude($t) {
    $g = 9.81;
    $v0 = 300;
    $h0 = 10000;
    return $h0 + $v0 * $t - 0.5 * $g * pow($t, 2);
}

function plot_trajectory() {
    $t = 0;
    while (true) {
        $h = calculate_altitude($t);
        if ($h < 0) {
            break;
        }
        echo "Time: $t, Altitude: $h\n";
        $t += 1;
        // Simulate pause
        usleep(10000);
    }
}

function main() {
    plot_trajectory();
}

main();

?>