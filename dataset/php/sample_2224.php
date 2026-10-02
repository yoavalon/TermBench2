<?php

function track_sequence($data, $precision) {
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        for ($j = $i + 1; $j < count($data); $j++) {
            $diff = abs($data[$i] - $data[$j]);
            if ($diff < $precision) {
                $result[] = [$i, $j, $diff];
            }
        }
    }
    return $result;
}

function analyze_data() {
    $sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    $precision = 1e-07;
    while (true) {
        $results = track_sequence($sequence, $precision);
        print_r($results);
    }
}

analyze_data();

?>