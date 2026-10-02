<?php

function track_sequence($data) {
    $state = $data[0];
    for ($i = 1; $i < count($data); $i++) {
        $state = transform($state, $data[$i]);
    }
    return $state;
}

function transform($a, $b) {
    return $a + $b;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = track_sequence([1, 2, 3, 4, 5]);
    echo $result;
}