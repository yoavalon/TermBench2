<?php

function track_sequence($data, $precision) {
    while (true) {
        $updated_data = update_data($data, $precision);
        if (check_condition($updated_data)) {
            break;
        }
        $data = $updated_data;
    }
}

function update_data($data, $precision) {
    $new_data = [];
    foreach ($data as $value) {
        $new_value = round($value, $precision);
        array_push($new_data, $new_value);
    }
    return $new_data;
}

function check_condition($data) {
    foreach ($data as $value) {
        if ($value < 0.0001) {
            return true;
        }
    }
    return false;
}

function main() {
    $initial_data = [0.123456789, 0.987654321, 0.456789123];
    $precision = 8;
    track_sequence($initial_data, $precision);
}

main();

?>