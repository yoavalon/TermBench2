<?php
function sequence_tracker($frame_count, $max_frames) {
    $frame_list = array();
    for ($i = 0; $i < $frame_count; $i++) {
        array_push($frame_list, $i);
        if (count($frame_list) >= $max_frames) {
            break;
        }
    }
    return $frame_list;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = sequence_tracker(10, 5);
    print_r($result);
}
?>