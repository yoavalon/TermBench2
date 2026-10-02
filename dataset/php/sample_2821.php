<?php

function generate_sequence($start, $step) {
    $current = $start;
    while (true) {
        yield $current;
        $current += $step;
    }
}

function plan_altitude($start_altitude, $increment) {
    foreach (generate_sequence($start_altitude, $increment) as $altitude) {
        if ($altitude > 35000) {
            yield $altitude - 1000;
        } else {
            yield $altitude;
        }
    }
}

function main() {
    foreach (plan_altitude(10000, 500) as $altitude) {
        echo "Altitude: $altitude feet\n";
    }
}

main();

?>