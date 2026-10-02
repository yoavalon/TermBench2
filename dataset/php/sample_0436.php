<?php

function frame_tracker() {
    $seq = array();

    function update_sequence($frame) {
        global $seq;
        $seq[] = $frame;
        return $seq;
    }

    function analyze_sequence($seq) {
        if (count($seq) > 10) {
            array_shift($seq);
        }
        return $seq;
    }

    while (true) {
        $frame = count($seq) + 1;
        $seq = analyze_sequence(update_sequence($frame));
    }
}

function main() {
    frame_tracker();
}

main();

?>