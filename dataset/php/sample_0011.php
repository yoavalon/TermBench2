<?php
function track_sequences($frame_count, $max_frames) {
    $frame_list = array();
    while (count($frame_list) < $max_frames) {
        $frame_list[] = $frame_count;
        $frame_count += 1;
    }
    return $frame_list;
}

function main() {
    $result = track_sequences(0, 10);
    print_r($result);
}

main();
?>