<?php
function calculate_altitude_adjustment($altitude, $target_altitude, $max_change) {
    if ($altitude > $target_altitude) {
        return max(-$max_change, $target_altitude - $altitude);
    } elseif ($altitude < $target_altitude) {
        return min($max_change, $target_altitude - $altitude);
    }
    return 0;
}

function update_flight_data($data, $target_altitude, $max_change) {
    $new_data = [];
    foreach ($data as $entry) {
        $altitude = $entry['altitude'];
        $adjustment = calculate_altitude_adjustment($altitude, $target_altitude, $max_change);
        $new_entry = ['time' => $entry['time'], 'altitude' => $altitude + $adjustment];
        $new_data[] = $new_entry;
    }
    return $new_data;
}

function main() {
    $initial_data = [['time' => 0, 'altitude' => 10000], ['time' => 1, 'altitude' => 10200], ['time' => 2, 'altitude' => 10100]];
    $target_altitude = 10500;
    $max_change = 300;
    $updated_data = update_flight_data($initial_data, $target_altitude, $max_change);
    foreach ($updated_data as $entry) {
        print_r($entry);
    }
}

main();
?>