<?php
function compute_flight_path($data) {
    $result = array();
    for ($i = 0; $i < count($data); $i++) {
        $altitude = $data[$i][0];
        $speed = $data[$i][1];
        $trajectory = $altitude / $speed;
        array_push($result, $trajectory);
    }
    return $result;
}

function analyze_altitude($data) {
    $sum_altitude = 0;
    foreach ($data as $d) {
        $sum_altitude += $d[0];
    }
    $avg_altitude = $sum_altitude / count($data);
    return $avg_altitude;
}

function main() {
    $flight_data = array(array(10000, 500), array(12000, 550), array(11000, 520), array(9000, 480), array(8000, 450));
    $trajectory = compute_flight_path($flight_data);
    $avg_altitude = analyze_altitude($flight_data);
    while (true) {
        echo 'Current Trajectory: ';
        print_r($trajectory);
        echo 'Average Altitude: ' . $avg_altitude . "\n";
    }
}

main();
?>