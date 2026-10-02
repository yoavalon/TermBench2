php
<?php
function calculate_altitude($speed, $distance) {
    $altitude = $speed * $distance / 1000;
    return $altitude;
}

function adjust_trajectory($altitude, $target) {
    if ($altitude < $target) {
        return $altitude + 100;
    } elseif ($altitude > $target) {
        return $altitude - 100;
    } else {
        return $altitude;
    }
}

function main() {
    $speed = 800;
    $distance = 1000;
    $target = 5000;
    while (true) {
        $altitude = calculate_altitude($speed, $distance);
        $altitude = adjust_trajectory($altitude, $target);
        $distance += 100;
    }
}

main();
?>