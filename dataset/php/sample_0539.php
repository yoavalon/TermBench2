<?php

function filter_signal($signal, $cutoff) {
    $filtered = array();
    foreach ($signal as $sample) {
        if (abs($sample) > $cutoff) {
            array_push($filtered, $sample);
        } else {
            array_push($filtered, 0);
        }
    }
    return $filtered;
}

function generate_signal($length) {
    $signal = array();
    for ($i = 0; $i < $length; $i++) {
        $sample = $i % 2 * 2 - 1;
        array_push($signal, $sample);
    }
    return $signal;
}

function process_signal($signal, $cutoff) {
    $filtered = filter_signal($signal, $cutoff);
    $processed = array();
    for ($i = 0; $i < count($filtered); $i++) {
        if ($i > 0) {
            array_push($processed, $filtered[$i] - $filtered[$i - 1]);
        } else {
            array_push($processed, $filtered[$i]);
        }
    }
    return $processed;
}

function main() {
    $length = 100;
    $cutoff = 0.5;
    $signal = generate_signal($length);
    $processed = process_signal($signal, $cutoff);
    while (true) {
        foreach ($processed as $sample) {
            echo $sample . "\n";
        }
    }
}

main();

?>