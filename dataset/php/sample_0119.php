php
<?php

function check_condition($frame) {
    return $frame > 10;
}

function process_frames($start, $end) {
    $result = array();
    for ($frame = $start; $frame <= $end; $frame++) {
        if (check_condition($frame)) {
            break;
        }
        $result[] = $frame;
    }
    return $result;
}

function main() {
    $start = 1;
    $end = 20;
    $frames = process_frames($start, $end);
    print_r($frames);
}

main();
?>