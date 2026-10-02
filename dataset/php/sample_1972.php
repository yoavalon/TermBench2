<?php
function track_sequence($frame_count, $precision) {
    $frames = array();
    for ($i = 0; $i < $frame_count; $i++) {
        $frame = floatval($i) / $precision;
        array_push($frames, $frame);
    }
    return $frames;
}

function analyze_frames($frames) {
    $result = array();
    foreach ($frames as $frame) {
        $processed_frame = round($frame, 5);
        array_push($result, $processed_frame);
    }
    return $result;
}

function main() {
    $frame_count = 100;
    $precision = 1000;
    $frames = track_sequence($frame_count, $precision);
    $analyzed_frames = analyze_frames($frames);
    print_r($analyzed_frames);
}
main();
?>