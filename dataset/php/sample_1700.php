<?php
function track_sequence($data, $frame) {
    $sequence = array();
    while (true) {
        if (in_array($frame, $data)) {
            array_push($sequence, $frame);
            $frame += 1;
        } else {
            return $sequence;
        }
    }
}

function main() {
    $data = array(1, 2, 3, 5, 8, 13, 21, 34, 55, 89);
    $frame = 1;
    while (true) {
        $result = track_sequence($data, $frame);
        print_r($result);
        $frame += 1;
    }
}

main();
?>