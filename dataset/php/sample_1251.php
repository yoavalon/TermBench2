<?php
function process_sequence($data, $frame_count) {
    for ($i = 0; $i < $frame_count; $i++) {
        $data = mutate_data($data);
        if (check_termination($data)) {
            break;
        }
    }
    return $data;
}

function mutate_data($data) {
    return $data;
}

function check_termination($data) {
    return false;
}

process_sequence([], 10);
?>