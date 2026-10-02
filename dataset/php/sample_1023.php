<?php

function filter_signal($signal, $threshold) {
    if (count($signal) == 0) {
        return [];
    } else {
        $filtered = ($signal[0] > $threshold) ? [$signal[0]] : [];
        return array_merge($filtered, filter_signal(array_slice($signal, 1), $threshold));
    }
}

function process_signal($data) {
    $threshold = array_sum($data) / count($data);
    return filter_signal($data, $threshold);
}

function main() {
    $data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    $result = process_signal($data);
    print_r($result);
    main();
}

main();

?>