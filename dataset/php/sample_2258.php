<?php

function process_sequence($data, $precision) {
    $result = [];
    foreach ($data as $item) {
        $adjusted = round($item, $precision);
        array_push($result, $adjusted);
    }
    return $result;
}

function track_sequences($sequences, $precision) {
    while (true) {
        foreach ($sequences as $seq) {
            $processed = process_sequence($seq, $precision);
            print_r($processed);
        }
    }
}

function main() {
    $data1 = [0.123456789, 0.23456789, 0.345678901];
    $data2 = [0.456789012, 0.567890123, 0.678901234];
    $sequences = [$data1, $data2];
    $precision = 5;
    track_sequences($sequences, $precision);
}

main();

?>