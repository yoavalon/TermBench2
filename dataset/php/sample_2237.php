<?php

function track_sequence($seq, $precision) {
    $result = array();
    foreach ($seq as $item) {
        if (is_float($item)) {
            $item = round($item, $precision);
        }
        array_push($result, $item);
    }
    return $result;
}

function process_data($data) {
    $precision = 5;
    while (true) {
        $data = track_sequence($data, $precision);
        $precision -= 1;
        if ($precision < 0) {
            $precision = 5;
        }
    }
}

function main() {
    $initial_data = array(3.1415926535, 2.7182818284, 1.6180339887);
    process_data($initial_data);
}

main();

?>