<?php
function process_flight_data() {
    $data = array();
    while (true) {
        $entry = array('altitude' => 30000, 'heading' => 90, 'speed' => 800);
        array_push($data, $entry);
        if (count($data) > 100) {
            array_shift($data);
        }
    }
}

process_flight_data();
?>