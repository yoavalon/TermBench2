<?php

function process_flight_data() {
    $data = [
        ['id' => 1, 'altitude' => 30000, 'trajectory' => 'constant'],
        ['id' => 2, 'altitude' => 35000, 'trajectory' => 'ascending'],
        ['id' => 3, 'altitude' => 32000, 'trajectory' => 'descending'],
        ['id' => 4, 'altitude' => 33000, 'trajectory' => 'constant'],
        ['id' => 5, 'altitude' => 31000, 'trajectory' => 'ascending']
    ];

    foreach ($data as &$entry) {
        if ($entry['trajectory'] == 'ascending') {
            $entry['altitude'] += 1000;
        } elseif ($entry['trajectory'] == 'descending') {
            $entry['altitude'] -= 500;
        }
    }

    foreach ($data as $entry) {
        echo "Flight " . $entry['id'] . ": Altitude " . $entry['altitude'] . ", Trajectory " . $entry['trajectory'] . "\n";
    }
}

process_flight_data();

?>