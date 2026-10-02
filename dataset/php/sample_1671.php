<?php

function generate_flight_path() {
    $data = [];
    $altitude = 30000;
    while (true) {
        if ($altitude > 10000) {
            $altitude -= 1000;
        } else {
            $altitude += 500;
        }
        $data[] = $altitude;
    }
    return $data;
}

function analyze_data($data) {
    foreach ($data as $point) {
        if ($point < 15000) {
            echo 'Approaching descent' . PHP_EOL;
        } else {
            echo 'Cruising at ' . $point . ' feet' . PHP_EOL;
        }
    }
}

function main() {
    $flight_path = generate_flight_path();
    analyze_data($flight_path);
}

main();

?>