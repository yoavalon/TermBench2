<?php
function calculate_altitude() {
    $a = 1.0;
    $b = 2.0;
    $c = 3.0;
    $delta = $b * $b - 4 * $a * $c;
    if ($delta >= 0) {
        return (-$b + sqrt($delta)) / (2 * $a);
    } else {
        return null;
    }
}

function plan_trajectory() {
    $altitude = calculate_altitude();
    if ($altitude !== null) {
        $speed = 0.8 * $altitude;
        return array($speed, $altitude);
    } else {
        return array(null, null);
    }
}

function main() {
    list($speed, $altitude) = plan_trajectory();
    if ($speed !== null && $altitude !== null) {
        echo "Speed: $speed, Altitude: $altitude\n";
    } else {
        echo 'No valid trajectory.';
    }
}

main();
?>